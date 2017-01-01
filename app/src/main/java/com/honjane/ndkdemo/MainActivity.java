package com.honjane.ndkdemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.honjane.ndkdemo.model.Person;

import java.util.ArrayList;


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

        Log.i("main----addNum",jniUtils.addNum()+"");
        Log.i("main----name",jniUtils.name);

        //传参数
        Log.i("main----intMethod",jniUtils.intMethod(4)+"");
        Log.i("main----booleanMethod",jniUtils.booleanMethod(true)+"");
        Log.i("main----stringMethod",jniUtils.stringMethod("hello"));
        Log.i("main----intArrayMethod",jniUtils.intArrayMethod(new int[]{3,5,6,12,46,33})+"");
        Log.i("main----objectMethod",jniUtils.objectMethod(new Person()).toString()+"");

        //field
        Log.i("main----age修改前",jniUtils.getAge()+"");
        jniUtils.accessPrivateField();
        Log.i("main----age修改后",jniUtils.getAge()+"");

        //method
        Log.i("main----sex赋值前",jniUtils.getSex());
        jniUtils.accessPublicMethod();
        Log.i("main----sex赋值后",jniUtils.getSex());


        Log.i("main----height调用java方法", JNIUtils.getHeight()+"");

        Log.i("main----height调用JNI方法",jniUtils.accessStaticMethod()+"");
        Log.i("main----调用java super方法",jniUtils.accessSuperMethod());

        ArrayList<Person> personList = new ArrayList<>();
        Person person;
        for (int i =0 ;i<3;i++){
            person = new Person();
            person.setName("lily");
            person.setAge(10+i);
            personList.add(person);
        }
        Log.i("main----输出java list",personList.toString());
        Log.i("main----输出jni list",jniUtils.personArrayListMethod(personList).toString());


        //字符串处理

        Log.i("main----handlerString",jniUtils.handlerString(" happy new year"));
        byte [] bytes = jniUtils.handlerStrToByte("honjane");
        for (byte b : bytes) {
            Log.i("main---handlerStrToByte", (char)b+"");
        }

    }


}
