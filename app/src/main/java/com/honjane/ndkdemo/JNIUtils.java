package com.honjane.ndkdemo;

import com.honjane.ndkdemo.model.Person;

import java.util.ArrayList;

/**
 * Created by honjane on 2016/12/24.
 */

public class JNIUtils extends SuperUtils{

    public int num = 10;

    public native int addNum();

    //field ----
    public static String name = "honjane";

    public native void accessStaticField();

    private int age = 21;

    public int getAge(){
        return age;
    }

    public native void accessPrivateField();

    //method --------
    private String sex = "female";

    private void setSex(String sex){
        this.sex = sex;
    }

    public String getSex(){
        return sex;
    }

    public native void accessPublicMethod();



    private static int height = 160;

    public static int getHeight(){
        return height;
    }

    public native int accessStaticMethod();

    public native String accessSuperMethod();


    public native void printC();



    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String variableJNI(String arr, int len);

    /**
     * 传参数
     */
    public native int intMethod(int n);

    public native boolean booleanMethod(boolean bool);

    public native String stringMethod(String text);

    public native int intArrayMethod(int[] intArray);

    public native Person objectMethod(Person person);

    public native ArrayList<Person> personArrayListMethod(ArrayList<Person> persons);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

}
