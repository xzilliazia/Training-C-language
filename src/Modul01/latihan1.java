package Modul01;

//player
class  Player{
    String name;
    double health;
    
    //object member
    Weapon weapon;
    Armor armor;
    Player (String name, double health){
        this.name = name; 
        this.health = health;

    }

    void equipWeapon(Weapon weapon){
        this.weapon = weapon;
    }
    void equipArmor(Armor armor){
        this.armor = armor;
    }
    void dislpay(){
        System.out.println("\nName : " + this.name);
        System.out.println("Health : " + this.health + " hp");
        this.weapon.display();
        this.armor.display();
    }
}
//senjata
class Weapon{
    double attack;
    String name;
    Weapon(String name, double attack){
        this.attack = attack;
        this.name = name;
    }
    void display(){
        System.out.println("Weapon : " + this.name + " , Attack : " + this.attack);
    }
}
//armor
class Armor{
    double defence;
    String name;

    Armor(String name, double defence){
        this.name = name;
        this.defence = defence;
    }
    void display(){
        System.out.println("Armor : " + this.name + " , Defence : " + this.defence);
    }
}


public class latihan1 {
    
    public static void main(String[] args) {
        //object player
        Player player1 = new Player("Jono",100);
        
        //object weapon
        Weapon sword = new Weapon("sword", 15);

        //object armor 
        Armor besi = new Armor("Iron", 10);

        //perlengkapan player 1
        player1.equipWeapon(sword);
        player1.equipArmor(besi);
        player1.dislpay();

    }
}
