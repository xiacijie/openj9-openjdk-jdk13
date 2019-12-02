#include "../omr/compiler/optimizer/OWLTypes.hpp"
#include "../omr/compiler/optimizer/OWLAnalyser.hpp"
#include "../omr/compiler/optimizer/OWLJNIClient.hpp"
#include "../omr/compiler/optimizer/OWLShrikeBTConstructor.hpp"
#include "../omr/compiler/optimizer/OWLDeserializer.hpp"
#include "../omr/compiler/optimizer/OWLJNIConfig.hpp"
#include "../omr/compiler/optimizer/OWLVerifier.hpp"
#include <vector>

using namespace std;
int main(int argc, char*[] argv){

    if (TR_OWLJNIClient::startJVM()){
        TR_OWLJNIClient *jniClient = TR_OWLJNIClient::getInstance();

        TR_OWLDeserializer* deserializer = new TR_OWLDeserializer();
        
        deserializer->deserialize("/Users/jackxia/Project/IBM/openj9-openjdk-jdk13/OWL/OWL.log");

        vector<TranslationUnit> translationUnits = deserializer->getTranslationUnits();
        MethodInfo methodInfo = deserializer->getMethodInfo();
        

        TR_OWLShrikeBTConstructor* constructor = new TR_OWLShrikeBTConstructor(jniClient);
        vector<jobject> shrikeBTInstructions = constructor->constructShrikeBTInstructions(translationUnits);
        TR_OWLAnalyser *analyser = new TR_OWLAnalyser(jniClient);
        analyser->analyse(shrikeBTInstructions);

        TR_OWLVerifier *verifier = new TR_OWLVerifier(jniClient);
        bool status = verifier->verify(&shrikeBTInstructions[0], shrikeBTInstructions.size(), false, true, methodInfo.className, methodInfo.signature);

        if (status) {
            printf("Successful to verify shrikeBT instruction!\n");
        }
        else {
            printf("Fail to verify shrikeBT instructions\n");
        }

        delete deserializer;
        delete verifier;
        delete analyser;
        delete constructor;
    }
    else{
        printf("JVM cannot be start!\n");
        exit(1);
    }
    TR_OWLJNIClient::destroyJVM();
    TR_OWLJNIClient::destroyInstance();

    return 0;

    
}
