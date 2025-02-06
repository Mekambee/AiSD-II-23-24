import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Skarbonki {
    private static final int n_max = 1000000;
    private int liczba_skarbonek;
    private int[] skarbonki;
    private int[] degrees;
    private int[] queue;
    private int queueTop;
    private File inputFile;

    public Skarbonki(File inputFile) {
        this.inputFile = inputFile;
        skarbonki = new int[n_max];
        degrees = new int[n_max];
        queue = new int[n_max];

        try {
            Scanner scanner = new Scanner(inputFile);
            this.liczba_skarbonek = scanner.nextInt();
            for (int i = 0; i < liczba_skarbonek; i++) {
                skarbonki[i] = scanner.nextInt() - 1;
                degrees[skarbonki[i]]++;
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Nie znaleziono pliku!");
            e.printStackTrace();
        }

        for (int i = 0; i < liczba_skarbonek; i++) {
            if (degrees[i] == 0) {
                queue[queueTop++] = i;
            }
        }

        for (int i = 0; i < queueTop; i++) {
            int x = queue[i];
            degrees[skarbonki[x]]--;
            if (degrees[skarbonki[x]] == 0) {
                queue[queueTop++] = skarbonki[x];
            }
        }

        int minimalBreaks = 0;
        for (int i = 0; i < liczba_skarbonek; i++) {
            if (degrees[i] == 0) continue;
            minimalBreaks++;
            int j = i;
            do {
                degrees[j] = 0;
                j = skarbonki[j];
            } while (j != i);
        }
        System.out.println("Wynik:\n " + "Minimalna liczba skarbonek, które musimy zbić wynosi: " + minimalBreaks);
    }
}
