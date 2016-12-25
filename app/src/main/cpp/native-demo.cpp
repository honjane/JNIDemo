#include <jni.h>
#include <string.h>
#include <stdio.h>

//调用c++printf函数
extern "C"
void Java_com_honjane_ndkdemo_JNIUtils_printC( JNIEnv* env, jobject jobj){

    printf("JNI printf : hello JNI");
}

extern "C"
jint Java_com_honjane_ndkdemo_JNIUtils_intMethod( JNIEnv* env, jobject jobj,jint num){

    return num*num;
}
extern "C"
jboolean Java_com_honjane_ndkdemo_JNIUtils_booleanMethod(JNIEnv* env,jobject jobj,jboolean flag){

    return !flag;
}
extern "C"
jstring Java_com_honjane_ndkdemo_JNIUtils_stringMethod(JNIEnv* env,jobject jobj,jstring jstr){
    const char * str = env->GetStringUTFChars(jstr,0);
    char c[120] = "lily ";
    strcat(c,str);
    env->ReleaseStringUTFChars(jstr,str);
    return env->NewStringUTF(c);
}

extern "C"
jint  Java_com_honjane_ndkdemo_JNIUtils_intArrayMethod(JNIEnv* env,jobject jobj,jintArray jarr){
     jint len=0,sum=0;
     len = env->GetArrayLength(jarr);
     jint* body = env->GetIntArrayElements(jarr,0);
     jint i=0;
     for(;i<len;i++){
        sum+=body[i];
     }
    return sum;
}