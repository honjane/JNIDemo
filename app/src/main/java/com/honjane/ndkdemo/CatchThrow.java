package com.honjane.ndkdemo;

import java.util.NoSuchElementException;

/**
 * Created by honjane on 2016/11/27.
 */

public class CatchThrow {

    public native void doit() throws IllegalArgumentException;
    public native void JNUThrowByName(String name,String msg) throws NoSuchElementException;
    private void callback() throws NullPointerException{
        throw new NullPointerException("java null prointer");
    }

    static {
        System.loadLibrary("native-lib");
    }
}
