#include <jni.h>
#include <string>
#include <stdio.h>

jobject java_com_honjane_ndkdemo_JNIUtils_variableJNI(JNIEnv *env, jobject jobj,jchar * jchr, jint len){
    //1。错误的定义全局变量
    static jclass jstrClass = NULL;
    jmethodID mid;
    jcharArray jarr;
    jobject result;
    if(jstrClass == NULL){
        jstrClass = env->FindClass("java/lang/String");
        if(jstrClass == NULL){

            return NULL;
        }
    }
    mid = env->GetMethodID(jstrClass,"<init>","([C)V");
    if(mid == NULL){
        return NULL;
    }
    jarr = env->NewCharArray(len);
    if(jarr == NULL){
        return NULL;
    }
    env->SetCharArrayRegion(jarr,0,len,jchr);
    result = env->NewObject(jstrClass,mid,jarr);
    env->DeleteLocalRef(jarr);
    return result;
}