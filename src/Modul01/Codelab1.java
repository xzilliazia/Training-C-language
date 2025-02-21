package Modul01;
import java.time.LocalDate;
import java.util.Scanner;

public class Codelab1 {
    public static void main(String[] args) {

        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Nama: ");
            String nama = input.nextLine();

            System.out.print("Masukkan Jenis Kelamin (L/P): ");
            String gender = input.next();
            if (gender.equalsIgnoreCase("l")){
                gender = "Laki-laki";
            }
            else if(gender.equalsIgnoreCase("p")){
                gender = "Perempuan";
            }

            System.out.print("Tahun Lahir : ");
            int timeuser = input.nextInt();
            int timenow = LocalDate.now().getYear();
            int ages = timenow - timeuser;
            
            System.out.println("\n===DATA ANDA===");
            System.out.println("Nama anda\t: " + nama);
            System.out.println("Jelis Kelamin\t: " + gender);
            System.out.println("Umur\t\t:" + ages + " tahun");
        }
    }
}
