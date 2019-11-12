#include "../omr/compiler/optimizer/OWLTypes.hpp"
#include "../omr/compiler/optimizer/OWLAnalyser.hpp"
#include "../omr/compiler/optimizer/OWLJNIClient.hpp"
#include "../omr/compiler/optimizer/OWLShrikeBTConstructor.hpp"
#include "../omr/compiler/optimizer/OWLDeserializer.hpp"
#include <vector>

using namespace std;
int main(){

    if (TR_OWLJNIClient::startJVM()){
        TR_OWLJNIClient *jniClient = TR_OWLJNIClient::getInstance();
        TR_OWLDeserializer* deserializer = new TR_OWLDeserializer();
        vector<OWLInstruction> owlInstructions = deserializer->deserialize();
        delete deserializer;

        TR_OWLShrikeBTConstructor* constructor = new TR_OWLShrikeBTConstructor(jniClient);
        vector<jobject> shrikeBTInstructions = constructor->constructShrikeBTInstructions(owlInstructions);
        TR_OWLAnalyser * analyser = new TR_OWLAnalyser(jniClient);
        analyser->analyse(shrikeBTInstructions);
        
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
