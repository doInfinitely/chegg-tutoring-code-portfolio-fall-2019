#include <stdio.h>
#include <errno.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

struct Node {
	int value;
	int count;
	struct Node *next;
	struct Node *next2;
	char key[1024];
};

int buckets;

int hash_code(char w[]) {
	int output = 0;
	int i = 0;
	while(w[i] != '\0') {
		output += (int) w[i];
		++i;
	}
	return output % buckets;
}

struct Node *hash_table[];
int doc_count;

void hash_table_insert(char w[], int doc) {
	int code = hash_code(w);
	struct Node *current = hash_table[code];
	struct Node *previous = NULL;
	while (current != NULL && strcmp(current->key,w) != 0) {
		previous = current;
		current = current->next;
	}
	
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->value = doc;
	node->count = 1;
	node->next = NULL;
	node->next = NULL;
	strcpy(node->key, w);

	if (previous == NULL && current == NULL) {
	   	hash_table[code] = node;
	   	//current = hash_table[code];
	} else if (current == NULL) {
		previous->next = node;
	    current = previous->next;
	} else {
		while(current != NULL && current->value != doc) {
			previous = current;
			current = current->next2;
		}
		if (current != NULL) {
			current->count++;
		} else {
			previous->next2 = node;
			//current = previous->next2;
		}
	}
	//printf("%d/%s/%d\n", current->count, current->key, current->value);
}

int hash_table_find(char w[], int doc) {
	int code = hash_code(w);
	struct Node *current = hash_table[code];
	struct Node *previous = NULL;
	while (current != NULL && strcmp(current->key,w) != 0) {
		previous = current;
		current = current->next;
	}
	if (current != NULL) {
		while(current != NULL && current->value != doc) {
			previous = current;
			current = current->next2;
		}
		if (current != NULL) {
			return current->count;
		}
	}
	return 0;
}

void stop_word() {
	int i = ;
	current = hash_table[i];
	while (current != NULL) {
		cur2 = current;
		while (cur2 != NULL) {
			
			cur2 = cur2->next;
		}
		current = current->next;
	}
}

struct Node ** train(glob_t results) {
	for (int i = 0; i < results.gl_pathc; i++) {
		printf("%s\n", results.gl_pathv[i]);
		FILE *f = fopen(results.gl_pathv[i], "r");
		char w[1024];
    	while (fscanf(f, " %1023s", w) == 1) {
			//printf("%s\n", w);
        	hash_table_insert(w, i+1);
    	}
		fclose(f);
	}
	return hash_table;
}

void rank(char w[], double ranking[]) {
	int tf[doc_count];
	int df = 0;
	for (int i = 0; i < doc_count; ++i) {
		tf[i] = hash_table_find(w, i+1);
		if (tf[i] > 0) {
			++df;
		}
	}
	for (int i = 0; i < doc_count; ++i) {
		if (df > 0) {
			ranking[i] += tf[i]*log(1.0*doc_count/df);
		}
	}
}

void read_query(char *query) {
	char *w;
	w = strtok(query, " ,.-;:");
	double ranking[doc_count];
	while (w != NULL) {
		rank(w, ranking);
		w = strtok(NULL, " ,.-;:");
	}
	FILE *f = fopen("search_scores.txt", "w");
	for (int i = 0; i < doc_count; ++i) {
		fprintf(f, "D%d:%f\n", i+1, ranking[i]);
	}
	fclose(f);

}

int main(int argc, char **argv) {
	buckets = atoi(argv[1]);
	hash_table[buckets];
	for (int i = 0; i < buckets; ++i) {
		hash_table[i] = NULL;
	}
	glob_t results;
	int ret = glob("p5docs/*.txt", 0, NULL, &results);
	doc_count = results.gl_pathc;
	train(results);
	read_query(argv[2]);
}
