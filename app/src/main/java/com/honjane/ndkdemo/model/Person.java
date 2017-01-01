package com.honjane.ndkdemo.model;

/**
 * Created by honjane on 2016/12/31.
 */

public class Person {
    private String name;
    private int age;


    public Person() {
    }

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Person :{ name: "+name+",age: "+age+"}";
    }


}
