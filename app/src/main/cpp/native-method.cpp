#include <jni.h>
#include <string.h>
#include <stdio.h>


//访问java中public方法
extern "C"
void Java_com_honjane_ndkdemo_JNIUtils_accessPublicMethod( JNIEnv* env, jobject jobj){
    //1.获得实例对应的class类
    jclass jcls = env->GetObjectClass(jobj);

    //2.通过class类找到对应的method id
    //setSex 为java类中方法名，Ljava.lang.String; 为变量的类型String
    jmethodID jmid = env->GetMethodID(jcls,"setSex","(Ljava/lang/String;)V");
    //定义一个性别赋值给java中的方法
    char c[10] = "male";
    jstring jsex = env->NewStringUTF(c);
    //3.通过obj获得对应的method
    env->CallVoidMethod(jobj,jmid,jsex);
}




//访问java中static方法
extern "C"
jint Java_com_honjane_ndkdemo_JNIUtils_accessStaticMethod( JNIEnv* env, jobject jobj){
    //1.获得实例对应的class类
    jclass jcls = env->GetObjectClass(jobj);

    //2.通过class类找到对应的method id
    jmethodID jmid = env->GetStaticMethodID(jcls,"getHeight","()I");

    //3.静态方法通过class获得对应的method
    return env->CallStaticIntMethod(jcls,jmid);
}





//访问java中父类方法
extern "C"
jstring Java_com_honjane_ndkdemo_JNIUtils_accessSuperMethod( JNIEnv* env, jobject jobj){
    //1.通过反射获得父类的class类
    jclass jpcls = env->FindClass("com/honjane/ndkdemo/SuperUtils");
    if(jpcls == NULL){
        char c[10] = "error";
        return env->NewStringUTF(c);
    }
    //2.通过class类找到对应的method id
    jmethodID jmid = env->GetMethodID(jpcls,"hello","(Ljava/lang/String;)Ljava/lang/String;");
    char c[20] = "happy new year";
    jstring new_str = env->NewStringUTF(c);
    //3.静态方法通过class获得对应的method
    return (jstring)env->CallNonvirtualObjectMethod(jobj,jpcls,jmid,new_str);
}

