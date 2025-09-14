#pragma once

// 1. Include libraries properly
// 2. Find out how to make a custom QtQuick widget using only C++
// 3. Initialise OpenGL, create and show window.
// 4. Resize OpenGL context to exactly fit the QtQuick widget.
// 5. Subdelegate rendering (virtual function)
// 6. Input processing

#include <QSize>
#include <QRect>

#include <QObject>
#include <QQuickWidget>

#include <GLFW/glfw3.h>

// This is a widget which contains an OpenGL context
//
// - We create an external OpenGL window
// - We resize the window to always cover the widget's area.
class QuickGLWidget : public QQuickWidget {
        Q_OBJECT
        QML_ELEMENT
public:
        QuickGLWidget(QObject *parent = nullptr);
        ~QuickGLWidget() = default;

        // Is run every frame
        // Call gl- functions here
        virtual void paintThisFrame();

private:
        /* ===== Qt ===== */

        // Returns the absolute size and position of the widget
        //
        // Use .topLeft() to get the position in absolute (screen) terms.
        // Use .size() to get the widget's size.
        QRect widgetGeometry();

        /* ===== OpenGL ===== */
        GLFWwindow *m_glContext;

        bool initializeGL();
        GLFWwindow* createGLWindow();
        int mainWindowLoop();

        // Make sure the OpenGL window always covers
        // the same area as the QuickGLWidget.
        void resizeGLWindow(int x,
                            int y,
                            int width,
                            int height);
};
