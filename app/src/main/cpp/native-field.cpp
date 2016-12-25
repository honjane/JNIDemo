#include <jni.h>
#include <string.h>
#include <stdio.h>

//访问java对象中num属性，并对其作加法运算
extern "C"
jint Java_com_honjane_ndkdemo_JNIUtils_addNum( JNIEnv* env, jobject jobj){
    //1.获得实例对应的class类
    jclass jcls = env->GetObjectClass(jobj);

    //2.通过class类找到对应的field id
    //num 为java类中变量名，I 为变量的类型int
    jfieldID fid = env->GetFieldID(jcls,"num","I");

    //3.通过实例object获得对应的field
    jint jnum = env->GetIntField(jobj,fid);
    //add
    jnum += 10;

    return jnum;
}

//访问java中静态变量name，并对其赋值
extern "C"
void Java_com_honjane_ndkdemo_JNIUtils_accessStaticField( JNIEnv* env, jobject jobj){
    //1.获得实例对应的class类
    jclass jcls = env->GetObjectClass(jobj);

    //2.通过class类找到对应的静态field id
    //name 为java类中变量名，Ljava.lang.String; 为变量的类型String
    jfieldID fid = env->GetStaticFieldID(jcls,"name","Ljava.lang.String;");

    //3.通过class获得对应的静态field
    jstring jstr = (jstring)env->GetStaticObjectField(jcls,fid);
    // 将jstring类型转换成字符指针
    const char* cstr = env->GetStringUTFChars(jstr, JNI_FALSE);
    //定义字符数组
    char text[30] = "hello ";
    //拼接字符
    strcat(text, cstr);
    jstring new_str = env->NewStringUTF(text);

    // 将jstring类型的变量 ， 设置到java
    env->SetStaticObjectField(jcls, fid, new_str);
}


//访问java中私有变量age
extern "C"
void Java_com_honjane_ndkdemo_JNIUtils_accessPrivateField( JNIEnv* env, jobject jobj){

    jclass jcls = env->GetObjectClass(jobj);

    jfieldID jfid = env->GetFieldID(jcls,"age","I");

    jint jage = env->GetIntField(jobj, jfid);

    jage++;

    env->SetIntField(jobj, jfid, jage);
}