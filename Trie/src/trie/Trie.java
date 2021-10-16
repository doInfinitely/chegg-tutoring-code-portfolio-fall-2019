package trie;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * This class implements a Trie. 
 * 
 *
 */
public class Trie {
	
	// prevent instantiation
	private Trie() { }
	
	/**
	 * Builds a trie by inserting all words in the input array, one at a time,
	 * in sequence FROM FIRST TO LAST. (The sequence is IMPORTANT!)
	 * The words in the input array are all lower case.
	 * 
	 * @param allWords Input array of words (lowercase) to be inserted.
	 * @return Root of trie with all words inserted from the input array
	 */
	public static TrieNode buildTrie(String[] allWords) {
		/** COMPLETE THIS METHOD **/
		
		TrieNode root = new TrieNode(null, null, null);
		for (int i = 0; i < allWords.length; i++) {
			TrieNode current = root;
			Indexes index = new Indexes(i, (short)0, (short)(allWords[i].length()-1));
			while (index.startIndex <= index.endIndex) {
				TrieNode pSibling = searchSiblings(index, current.firstChild, allWords);
				if (pSibling == null) {
					TrieNode sibling = current.firstChild;
					if (sibling == null || index.endIndex-index.startIndex != sibling.substr.endIndex - sibling.substr.startIndex) {
						if (sibling == null) {
							current.firstChild = new TrieNode(index, sibling, null);
						} else {
							current.firstChild = new TrieNode(index, sibling, sibling.sibling);
							sibling.sibling = null;
							sibling.substr.startIndex = (short)(index.endIndex+1);
						}
					}
					current = current.firstChild;
					index = new Indexes(index.wordIndex, (short)(index.endIndex+1), (short)(allWords[i].length()-1));
				} else {
					TrieNode sibling = pSibling.sibling;
					if (sibling == null || index.endIndex-index.startIndex != sibling.substr.endIndex - sibling.substr.startIndex) {
						if (sibling == null) {
							current = new TrieNode(index, null, null);
						} else {
							current = new TrieNode(index, sibling, sibling.sibling);
							sibling.sibling = null;
							sibling.substr.startIndex = (short)(index.endIndex+1);
						}
						pSibling.sibling = current;
					} else {
						current = sibling;
					}
					index = new Indexes(index.wordIndex, (short)(index.endIndex+1), (short)(allWords[i].length()-1));
				}
			}
		}
		return root;
	}
	private static TrieNode searchSiblings(Indexes index, TrieNode firstChild, String[] allWords) {
		TrieNode pSibling = null;
		TrieNode sibling = firstChild;
		while (sibling != null) {
			short i = 0;
			while (i <= Math.min(index.endIndex-index.startIndex, sibling.substr.endIndex-sibling.substr.startIndex) && allWords[index.wordIndex].charAt(index.startIndex+i) == allWords[sibling.substr.wordIndex].charAt(sibling.substr.startIndex+i)) {
				i++;
			}
			if (i > 0) {
				index.endIndex = (short)(index.startIndex+i-1);
				return pSibling;
			}
			pSibling = sibling;
			sibling = sibling.sibling;
		}
		return pSibling;
	}



	
	/**
	 * Given a trie, returns the "completion list" for a prefix, i.e. all the leaf nodes in the 
	 * trie whose words start with this prefix. 
	 * For instance, if the trie had the words "bear", "bull", "stock", and "bell",
	 * the completion list for prefix "b" would be the leaf nodes that hold "bear", "bull", and "bell"; 
	 * for prefix "be", the completion would be the leaf nodes that hold "bear" and "bell", 
	 * and for prefix "bell", completion would be the leaf node that holds "bell". 
	 * (The last example shows that an input prefix can be an entire word.) 
	 * The order of returned leaf nodes DOES NOT MATTER. So, for prefix "be",
	 * the returned list of leaf nodes can be either hold [bear,bell] or [bell,bear].
	 *
	 * @param root Root of Trie that stores all words to search on for completion lists
	 * @param allWords Array of words that have been inserted into the trie
	 * @param prefix Prefix to be completed with words in trie
	 * @return List of all leaf nodes in trie that hold words that start with the prefix, 
	 * 			order of leaf nodes does not matter.
	 *         If there is no word in the tree that has this prefix, null is returned.
	 */
	public static ArrayList<TrieNode> completionList(TrieNode root,
										String[] allWords, String prefix) {
		int i = 0;
		int j = 0;
		TrieNode current = root;
		TrieNode sibling = null;
		while (i < prefix.length()) {
			sibling = current.firstChild;
			while (sibling != null && allWords[sibling.substr.wordIndex].charAt(sibling.substr.startIndex) != prefix.charAt(i)) {
				sibling = sibling.sibling;
			}
			if (sibling == null) {
				return null;
			}
			j = 0;
			while (j <= Math.min(sibling.substr.endIndex-sibling.substr.startIndex, prefix.length()-1)) {
				if (allWords[sibling.substr.wordIndex].charAt(sibling.substr.startIndex+j) != prefix.charAt(i+j)) {
					return null;
				}
				j++;
			}
			current = sibling;
			i += j;
		}
		if (j-1 == sibling.substr.endIndex - sibling.substr.startIndex) {
			ArrayList<TrieNode> output = new ArrayList<TrieNode>();
			LinkedList<TrieNode> queue = new LinkedList<TrieNode>();
			queue.add(sibling);
			while (queue.peek() != null) {
				current = queue.remove();
				if (current.substr.endIndex == allWords[current.substr.wordIndex].length()-1) {
					output.add(current);
				}
				sibling = current.firstChild;
				while (sibling != null) {
					queue.add(sibling);
					sibling = sibling.sibling;
				}
			}
			if (output.size() > 0) {
				return output;
			}
		}
		return null;
	}

	public static void print(TrieNode root, String[] allWords) {
		System.out.println("\nTRIE\n");
		print(root, 1, allWords);
	}
	
	private static void print(TrieNode root, int indent, String[] words) {
		if (root == null) {
			return;
		}
		for (int i=0; i < indent-1; i++) {
			System.out.print("    ");
		}
		
		if (root.substr != null) {
			String pre = words[root.substr.wordIndex]
							.substring(0, root.substr.endIndex+1);
			System.out.println("      " + pre);
		}
		
		for (int i=0; i < indent-1; i++) {
			System.out.print("    ");
		}
		System.out.print(" ---");
		if (root.substr == null) {
			System.out.println("root");
		} else {
			System.out.println(root.substr);
		}
		
		for (TrieNode ptr=root.firstChild; ptr != null; ptr=ptr.sibling) {
			for (int i=0; i < indent-1; i++) {
				System.out.print("    ");
			}
			System.out.println("     |");
			print(ptr, indent+1, words);
		}
	}
 }
