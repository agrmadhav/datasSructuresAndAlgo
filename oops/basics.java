class Person{
    String name;
    int age;

    static int count;

    public Person(){
        this("sanchit",20);
        count++;
    }

    public Person(String name,int age){
        // this();
        this.name = name;
        this.age = age;
    }

    void walk(){
        System.out.println(name + " is walking");
    }
    void eat(){
        System.out.println(name + " is eating food");
    }
    void walk(int steps){
        System.out.println(name + " has walked " + steps + " steps");
    }
}

class Developer extends Person{
    public Developer(String name , int age){
        super(name,age);
    }
    void walk(int steps){
        System.out.println("Developer " + name + " has walked " + steps + " steps");
    }
}
public class basics{
    public static void main(String[] args) {

       Person p1 = new Person();
       p1.age = 21;
       p1.name = "Madhav";
       Person p2 = new Person();
       p2.age = 4;
       p2.name = "bachaa";
       System.out.println(p1.age + " " + p1.name);
       System.out.println(p2.age + " " + p2.name);
       p1.walk();
       p2.eat();
       p2.walk(10);
       Person p3 = new Person("rohan",9);
       System.out.println(p3.age + " " +  p3.name);
       System.out.println(Person.count);

       Developer d1 = new Developer("sanchit",12);
       d1.walk(10);

       Person p4 = new Person();
       System.out.println(p4.name + " " + p4.age);
    }
}