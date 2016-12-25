package com.honjane.ndkdemo;

/**
 * Created by honjane on 2016/12/24.
 */

public class JNIUtils {

    public int num = 10;

    public native int addNum();

    public static String name = "honjane";

    public native void accessStaticField();

    private int age = 21;

    public native void accessPrivateField();


    public native void printC();

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String variableJNI(String arr, int len);

    /**
     * demo
     */
    public native int intMethod(int n);

    public native boolean booleanMethod(boolean bool);

    public native String stringMethod(String text);

    public native int intArrayMethod(int[] intArray);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public int getAge(){
        return age;
    }
}
