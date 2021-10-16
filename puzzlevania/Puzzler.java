import java.util.Random;
import java.util.ArrayList;

class Puzzler {
	private static class Duelist {
		String name;
		double accuracy;
		boolean isAlive;
		public Duelist(String name, double accuracy) {
			this.name = name;
			this.accuracy = accuracy;
			this.isAlive = true;
		}
		public boolean ShootAtTarget(Duelist target) {
			Random rand = new Random();
			if (rand.nextDouble() <= this.accuracy) {
				target.isAlive = false;
				return true;
			}
			return false;
		}
	}

	public static void main(String[] args) {
		int[] counts = {0, 0, 0};
		int[] counts2 = {0, 0, 0};
		for (int i = 0; i < 10000; i++)
			counts[duel()]++;
		System.out.println("Aaron won " + counts[0] + "/10,000 duels or " + 100.0*counts[0]/10000);
		System.out.println("Bob won " + counts[1] + "/10,000 duels or " + 100.0*counts[1]/10000);
		System.out.println("Charlie won " + counts[2] + "/10,000 duels or " + 100.0*counts[2]/10000);
		System.out.println("With Aaron intentionally missing the first shot:");
		for (int i = 0; i < 10000; i++)
			counts2[duelThrow()]++;
		System.out.println("Aaron won " + counts2[0] + "/10,000 duels or " + 100.0*counts2[0]/10000);
		System.out.println("Bob won " + counts2[1] + "/10,000 duels or " + 100.0*counts2[1]/10000);
		System.out.println("Charlie won " + counts2[2] + "/10,000 duels or " + 100.0*counts2[2]/10000);
	}
	public static int duel() {
		Duelist aaron = new Duelist("Aaron", 1.0/3);
		Duelist bob = new Duelist("Bob", 1.0/2);
		Duelist charlieTheUnerring = new Duelist("Charlie", 1.0/3);
		ArrayList<Duelist> duelists = new ArrayList<Duelist>();
		duelists.add(aaron);
		duelists.add(bob);
		duelists.add(charlieTheUnerring);
		int lastAlive = 0;
		int alive = duelists.size();
		while (alive > 1) {
			for (int i = 0; i < duelists.size(); i++) {
				int deadlyIndex = -1;
				double deadlyAccuracy = 0;
				for(int j = 0; j < duelists.size(); j++) {
					if (j != i && duelists.get(j).isAlive && deadlyAccuracy < duelists.get(j).accuracy) {
						deadlyIndex = j;
						deadlyAccuracy = duelists.get(j).accuracy;
					}
				}
				if (deadlyIndex >= 0 && duelists.get(i).ShootAtTarget(duelists.get(deadlyIndex))) {
					alive--;
					if (alive == 1) {
						break;
					}
				}
			}
		}
		for (int i = 0; i < duelists.size(); i++) {
			if (duelists.get(i).isAlive)
				return i;
		}
		return -1;
	}
	public static int duelThrow() {
		Duelist aaron = new Duelist("Aaron", 1.0/3);
		Duelist bob = new Duelist("Bob", 1.0/2);
		Duelist charlieTheUnerring = new Duelist("Charlie", 1.0/3);
		ArrayList<Duelist> duelists = new ArrayList<Duelist>();
		duelists.add(aaron);
		duelists.add(bob);
		duelists.add(charlieTheUnerring);
		int lastAlive = 0;
		int alive = duelists.size();
		int rounds = 0;
		while (alive > 1) {
			for (int i = 0; i < duelists.size(); i++) {
				if (rounds == 0 && i == 0)
					continue;
				int deadlyIndex = -1;
				double deadlyAccuracy = 0;
				for(int j = 0; j < duelists.size(); j++) {
					if (j != i && duelists.get(j).isAlive && deadlyAccuracy < duelists.get(j).accuracy) {
						deadlyIndex = j;
						deadlyAccuracy = duelists.get(j).accuracy;
					}
				}
				if (deadlyIndex >= 0 && duelists.get(i).ShootAtTarget(duelists.get(deadlyIndex))) {
					alive--;
					if (alive == 1) {
						break;
					}
				}
			}
			rounds++;
		}
		for (int i = 0; i < duelists.size(); i++) {
			if (duelists.get(i).isAlive)
				return i;
		}
		return -1;
	}
}
