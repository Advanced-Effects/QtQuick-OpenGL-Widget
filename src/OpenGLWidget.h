#pragma once

#include <QObject>

#include <GLFW/glfw3.h>

// 1. Include libraries properly
// 2. Find out how to make a custom QtQuick widget using only C++
// 3. Initialise OpenGL, create and show window.
// 4. Resize OpenGL context to exactly fit the QtQuick widget.
// 5. Subdelegate rendering (virtual function)
// 6. Input processing

class QuickGLWidget {
public:
        QuickGLWidget(QObject *parent = nullptr);
        ~QuickGLWidget() = default;

        virtual void onDrawNextFrame();

private:
        GLFWwindow *m_glContext;

        // Make sure the OpenGL window always covers
        // the same area as the QuickGLWidget.
        void onWidgetResize(int x,
                            int y,
                            int width,
                            int height);
};
