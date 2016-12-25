package com.honjane.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        JNIUtils jniUtils = new JNIUtils();
        tv.setText(jniUtils.stringFromJNI());
//        Log.d("main",variableJNI("nihaoa",10));

        CatchThrow c = new CatchThrow();
        try {
//            c.doit();
            c.JNUThrowByName("callback", "this is c NoSuchElementException");
        } catch (Exception e) {
            Log.e("main---", "java in " + e.toString());
        }

        jniUtils.printC();
        jniUtils.accessStaticField();
        Log.i("main----intMethod",jniUtils.intMethod(4)+"");
        Log.i("main----addNum",jniUtils.addNum()+"");
        Log.i("main----name",jniUtils.name);
        Log.i("main----age修改前",jniUtils.getAge()+"");
        Log.i("main----booleanMethod",jniUtils.booleanMethod(true)+"");
        Log.i("main----stringMethod",jniUtils.stringMethod("nihao"));
        Log.i("main----intArrayMethod",jniUtils.intArrayMethod(new int[]{3,5,6,12,46,33})+"");


        jniUtils.accessPrivateField();
        Log.i("main----age修改后",jniUtils.getAge()+"");


    }


}
