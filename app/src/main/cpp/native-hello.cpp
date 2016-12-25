#include <jni.h>
#include <string>
#include <stdio.h>

jstring printHello(JNIEnv * env){
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
jstring
Java_com_honjane_ndkdemo_JNIUtils_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    //std::string hello = "Hello from C++";
   jstring hello = printHello(env);
    return hello;
}

