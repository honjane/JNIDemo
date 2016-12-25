#include <jni.h>
#include <string.h>
#include <stdio.h>

extern "C"
/**
*抛出异常的本地方法
*/
void
Java_com_honjane_ndkdemo_CatchThrow_doit(
        JNIEnv* env,
        jobject jobj) {
    //std::string hello = "Hello from C++";
    jthrowable exc;
    jclass jclasz = env->GetObjectClass(jobj);

    jmethodID mid = env->GetMethodID(jclasz,"callback","()V");
    if(mid == NULL){
        return;
    }
    env->CallVoidMethod(jobj,mid);
    //确定是否某个异常正被抛出
    exc = env->ExceptionOccurred();
    if(exc){
           jclass newExc;

            //本地代码通过调用 ExceptionDescribe 来输出 一个关于这个异常的描述信息，
           env->ExceptionDescribe();
           //通过调用 ExceptionClear 清除异常信系
           env->ExceptionClear();
           newExc = env->FindClass("java/lang/IllegalArgumentException");
           if(newExc == NULL){
            return;
           }
           //JNI 抛出的异常(例如，通过 ThrowNew 方法)不 被处理的话，不会立即终止本地方法的执行
           env->ThrowNew(newExc,"this is c exception");
    }
}


  /**
    异常工具类方法
    */
    extern "C"
    void Java_com_honjane_ndkdemo_CatchThrow_JNUThrowByName(JNIEnv *env , jobject jobj,jstring  jname, jstring jmsg)
    {
        const char * name = env->GetStringUTFChars(jname,0);
        const char * msg = env->GetStringUTFChars(jmsg,0);
        jclass clasz = env->FindClass(name);
        if(clasz != NULL){
            env->ThrowNew(clasz,msg);
        }
        env->DeleteLocalRef(clasz);
    }