#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    ofImage matCap;
    ofVboMesh mesh;
    ofShader shader;
    ofEasyCam cam;
    
    void setup() {
        ofEnableDepthTest();
        ofDisableArbTex();
        matCap.load("matcap.jpg");
        shader.load("sem");
        mesh.load("mesh.ply");
        cam.setTranslationKey('\t');
    }
    
    void draw() {
        ofBackgroundGradient(64, 0);
        cam.begin();
        shader.begin();
        shader.setUniformTexture("tMatCap", matCap, 1);
        float scale = ofGetHeight() / 3;
        ofScale(scale, scale, scale);
        mesh.draw();
        shader.end();
        cam.end();
    }
    
    void dragEvent(ofDragInfo dragInfo) {
        matCap.load(dragInfo.files[0]);
        matCap.update();
    }
};

int main() {
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	ofRunApp(new ofApp());
}
