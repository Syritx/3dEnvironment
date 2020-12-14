//
//  main.cpp
//  3dGLFW
//
//  Created by Syritx on 2020-12-04.
//

#include "libs.h"
#include "Plain.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    if (!glfwInit()) glfwTerminate();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    
    GLFWwindow* window = glfwCreateWindow(1000, 720, "hello", NULL, NULL);
    if (!window) glfwTerminate();
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();
    
    Plain plain = Plain();
        
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0,0,0,1);
        
        plain.render();
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 1;
}
