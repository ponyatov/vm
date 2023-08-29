import os, sys

from PyQt5.QtWidgets import \
    QApplication, QLabel, QMainWindow, QMenuBar, QMenu, QAction

class MainWindow(QMainWindow):
    def __init__(self, args=sys.argv):
        super().__init__()
        self.args = args
        self.menu()

    def menu(self):
        self.menu = QMenuBar(); self.setMenuBar(self.menu)
        self.file()
        self.help()

    def file(self):
        self.file = QMenu('&File'); self.menu.addMenu(self.file)

    def help(self):
        self.help = QMenu('&Help'); self.menu.addMenu(self.help)
        self.about()

    def about(self):
        self.about = QAction('&About\tF1'); self.help.addAction(self.about)


app = QApplication(sys.argv)
wMain = MainWindow(); wMain.show()
# label = QLabel(wMain,str(sys.argv))
# label.show()
app.exec_()
