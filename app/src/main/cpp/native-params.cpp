#include <jni.h>
#include <string.h>
#include <stdio.h>

//调用c++printf函数
extern "C"
void Java_com_honjane_ndkdemo_JNIUtils_printC( JNIEnv* env, jobject jobj){

    printf("JNI printf : hello JNI");
}

//传递int参数
extern "C"
jint Java_com_honjane_ndkdemo_JNIUtils_intMethod( JNIEnv* env, jobject jobj,jint num){

    return num*num;
}

//传递布尔类型
extern "C"
jboolean Java_com_honjane_ndkdemo_JNIUtils_booleanMethod(JNIEnv* env,jobject jobj,jboolean flag){

    return !flag;
}


//传递string类型
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


//传递person自定义对象给jni函数
extern "C"
jobject  Java_com_honjane_ndkdemo_JNIUtils_objectMethod(JNIEnv* env,jobject jobj,jobject jperson){
    jclass jcls = env->GetObjectClass(jperson);
//    jclass jcls =  env->FindClass("com/honjane/ndkdemo/model/Person"); //或反射得Person类引用

    if(jcls == NULL){
        return env->NewStringUTF("not find class");
    }
    jmethodID constrocMID = env->GetMethodID(jcls,"<init>","(ILjava/lang/String;)V");
    if(constrocMID == NULL){
        return env->NewStringUTF("not find constroc method");
    }

    jstring str = env->NewStringUTF("honjane");

    jobject new_ojb = env->NewObject(jcls,constrocMID,21,str);  //构造一个对象，调用该类的构造函数，并且传递参数

 return new_ojb;
}


//传递ArrayList<Person>集合给jni函数
extern "C"
jobject  Java_com_honjane_ndkdemo_JNIUtils_personArrayListMethod(JNIEnv* env,jobject jobj, jobject jlist){
    jclass jcls = env->GetObjectClass(jlist);
    if(jcls == NULL){
        return env->NewStringUTF("not find class");
    }
    jmethodID constrocMID = env->GetMethodID(jcls,"<init>","()V");
    if(constrocMID == NULL){
        return env->NewStringUTF("not find constroc method");
    }
    //创建一个Arraylist集合对象
    jobject list_obj = env->NewObject(jcls,constrocMID);
    //获取list的add方法id
    jmethodID list_add  = env->GetMethodID(jcls,"add","(Ljava/lang/Object;)Z");


    jclass jpersonCls = env->FindClass("com/honjane/ndkdemo/model/Person");

    jmethodID jpersonConstrocMID = env->GetMethodID(jpersonCls,"<init>","(ILjava/lang/String;)V");

   for(int i = 0 ; i < 3 ; i++)
       {
           jstring str = env->NewStringUTF("Native");
           //通过调用该对象的构造函数来new 一个 Student实例
           jobject per_obj = env->NewObject(jpersonCls , jpersonConstrocMID , 20+i ,str);  //构造一个person对象
           //执行Arraylist类实例的add方法，添加一个person对象
           env->CallBooleanMethod(list_obj ,list_add, per_obj);
       }

 return list_obj;
}