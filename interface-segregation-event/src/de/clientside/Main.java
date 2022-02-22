package de.clientside;

import de.tiere.PigTooFatListener;
import de.tiere.Schwein;



public class Main {

	private Metzger metzger = new Metzger();
	public static void main(String[] args) {
		new Main().run();

	}

	private void run() {
		Schwein piggy = new Schwein("Miss Piggy");

		piggy.addPigTooFatListener(metzger::schlachten);

		for (int i = 0; i < 11; i++) {
			piggy.fuettern();

		}

	}



	class Metzger {

		public void schlachten(Object tier) {
			System.out.println("Messer wetz!");
		}
	}

}



