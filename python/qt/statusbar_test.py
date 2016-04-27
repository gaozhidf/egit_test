#!/usr/bin/env python
#coding:utf-8
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class M(QMainWindow):
    list=[]
    def __init__(self):
        QMainWindow.__init__(self)
        self.textEdit=QTextEdit()
        self.setCentralWidget(self.textEdit)
        self.createActions()
        self.createMenus()
        self.createContextMenu()
        self.createToolBars()
        self.createStatusBar()
        self.createDockWidget()

        self.readSettings()
    def closeEvent(self,e):
        r = QMessageBox.question(self,self.tr("Title"), self.tr("Close?"),
                                 QMessageBox.Yes | QMessageBox.No)
        if r == QMessageBox.Yes:
            self.writeSettings()
            return e.accept()
        elif r == QMessageBox.No:
            return e.ignore()

    def contextMenuEvent(self,e):
        m=QMenu(self)
        m.addAction(self.closeAct)
        m.exec_(e.globalPos())
        
    def createActions(self):
        self.closeAct = QAction("Cl&ose", self, shortcut="Ctrl+F4",
                statusTip="Close the active window",
                triggered=self.close)
    def createMenus(self):
        self.fileMenu = self.menuBar().addMenu("&File")
        self.fileMenu.addAction(self.closeAct)
        self.fileMenu.addSeparator()
        action = self.fileMenu.addAction("&New")
        action.triggered.connect(self.newWindow)
    def createToolBars(self):
        self.fileToolBar = self.addToolBar("File")
        self.fileToolBar.addAction(self.closeAct)
    def createStatusBar(self):
        self.statusBar().showMessage("Ready")
        l = QLabel("hello world")
        self.statusBar().addPermanentWidget(l)
    def createContextMenu(self):
       self.textEdit.addAction(self.closeAct);
       self.textEdit.setContextMenuPolicy(Qt.ActionsContextMenu);
    def createDockWidget(self):
        dockWidget = QDockWidget(self.tr("Dock Widget"),self)
        dockWidget.setAllowedAreas(Qt.LeftDockWidgetArea |
                                 Qt.RightDockWidgetArea);
        #dockWidget->setWidget(dockWidgetContents);
        self.addDockWidget(Qt.LeftDockWidgetArea, dockWidget);
           
    def newWindow(self):
        w=M()
        M.list.append(w)
        w.show()
    def readSettings(self):
        settings = QSettings('ee.zsy', 'HelloWorld')
        pos = settings.value('pos', QPoint(200, 200)).toPoint()
        size = settings.value('size', QSize(400, 400)).toSize()
        self.move(pos)
        self.resize(size)

    def writeSettings(self):
        settings = QSettings('ee.zsy', 'HelloWorld')
        settings.setValue('pos', self.pos())
        settings.setValue('size', self.size())
        
if __name__ == '__main__':
    import sys
    a = QApplication(sys.argv)
    w = M()
    w.show() 
    sys.exit(a.exec_())
