#include <jni.h>
#include <string.h>
#include <stdio.h>

extern "C"
jstring Java_com_honjane_ndkdemo_JNIUtils_handlerString( JNIEnv* env, jobject jobj,jstring jstr){
      //utf8
      const char* chr = env->GetStringUTFChars(jstr,0);
      //unicode
      const jchar* chr1 = env->GetStringChars(jstr,0);

      jsize jlen = env->GetStringUTFLength(jstr);
      jsize jlen1 = env->GetStringLength(jstr);

       char c[120] = "你好 2017";
       //把chr拼接到c
       strcat(c,chr);

      jstring new_str = env->NewStringUTF(c);

      env->ReleaseStringUTFChars(jstr,chr);
      env->ReleaseStringChars(jstr,chr1);

    return new_str;
}


char * jstringToChar(JNIEnv * env,jstring jstr){

    char* rtn = NULL;
    //等到String的class
    jclass jcls = env->FindClass("java/lang/String");
    //定义string的编码格式
    jstring strcode = env->NewStringUTF("utf-8");
    //获得string的getBytes method Id
    jmethodID jmid = env->GetMethodID(jcls, "getBytes", "(Ljava/lang/String;)[B");
    //调用getBytes方法 返回一个jbyteArray
    jbyteArray byteArr= (jbyteArray)env->CallObjectMethod(jstr, jmid, strcode);

    jsize alen = env->GetArrayLength(byteArr);
    //数组指向一个byte指针
    jbyte* pbyte = env->GetByteArrayElements(byteArr, 0);
    if (alen > 0)
    {
        //申请数组长度+1个内存空间
        rtn = (char*)malloc(alen + 1);
        //从源pbyte所指的内存地址的起始位置开始拷贝alen个字节到目标rtn所指的内存地址的起始位置中
        memcpy(rtn, pbyte, alen);
        rtn[alen] = 0;
    }
    //释放
    env->ReleaseByteArrayElements(byteArr, pbyte, 0);
    return rtn;
}


//string to byte
extern "C"
jbyteArray Java_com_honjane_ndkdemo_JNIUtils_handlerStrToByte( JNIEnv* env, jobject jobj,jstring jstr){

    char * chr = NULL;
    chr =jstringToChar(env, jstr);

    jbyteArray RtnArr = NULL;  //下面一系列操作把chr转成jbyteArray 返回出去
    RtnArr = env->NewByteArray(strlen(chr));

    env->SetByteArrayRegion(RtnArr, 0, strlen(chr), (jbyte*)chr );

   //释放chr
   if(chr) {
        free(chr);
    }

    return RtnArr;
}