package Latihan;

class Mahasiswa {
    //data member
    String name;
    String nim;

    //Contructor
    Mahasiswa (String name, String nim){
        this.name = name;
        this.nim = nim;
    }

    //Method tanpa return dan tanpa parameter
    void show(){
        System.out.println("Nama : " + this.name);
        System.out.println("NIM : " + this.nim);
    }
    //method no return dan dengan parameter
    void setNama(String nama){
        this.name = nama;
    }
    //method dengan return dan no parameter
    String getNama(){
        return this.name;
    }
    String getNIM(){
        return this.nim;
    }
    //method dengan return dan parameter
    String sayHi(String message){
        return message + " Juga, nama saya adalah " + this.name;
    }
}

public class Method {
    public static void main(String[] args) {
        Mahasiswa mahasiswa1 = new Mahasiswa("darin", "121212");
        mahasiswa1.show();
        mahasiswa1.setNama("Jono");
        mahasiswa1.show();
        System.out.println(mahasiswa1.getNama());
        System.out.println(mahasiswa1.getNIM());

        String data = mahasiswa1.sayHi("Ganteng");
        System.out.println(data);

    }
}
