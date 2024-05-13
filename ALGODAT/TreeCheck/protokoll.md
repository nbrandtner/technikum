# Rekursive Funktionen:

#### von Luis Böhler und Niklas Brandtner

1. insertNodeIntoAVLTree(Node *node, int key):
Fügt einen neuen Knoten mit dem gegebenen Schlüssel in den AVL-Baum ein.
Sie ist rekursiv und hat eine Zeitkomplexität von O(log n).

2. calculateNodeHeight(Node *node):
Berechnet die Höhe eines Knotens im AVL-Baum.
Sie ist rekursiv und hat eine Zeitkomplexität von O(n).

3. checkIfTreeIsAVLTree(Node *root):
Überprüft, ob der Baum ein AVL-Baum ist.
Sie ist rekursiv und hat eine Zeitkomplexität von O(n).

4. calculateMinMaxAvgKeys(Node *root):
Berechnet den minimalen, maximalen und durchschnittlichen Schlüssel im AVL-Baum.
Sie ist rekursiv und hat eine Zeitkomplexität von O(n).

5. searchKeyInAVLTree(Node *root, int key):
Sucht einen gegebenen Schlüssel im AVL-Baum.
Sie ist rekursiv und hat eine Zeitkomplexität von O(log n).

6. checkIfExactSubtree(Node *tree, Node *subtree):
Überprüft, ob ein Baum ein exakter Unterbaum eines anderen Baums ist.
Sie ist rekursiv und hat eine Zeitkomplexität von O(n + m).

7. searchKeyAndPrintPath(Node *root, int key, string path = ""):
Sucht einen gegebenen Schlüssel im AVL-Baum und druckt den Pfad zum Schlüssel.
Sie ist rekursiv und hat eine Zeitkomplexität von O(log n).

8. convertAVLTreeToList(Node *root, vector<int> &list):
Konvertiert den AVL-Baum in eine Liste von Schlüsseln.
Sie ist rekursiv und hat eine Zeitkomplexität von O(n).

Die Zeitkomplexität der meisten dieser Funktionen ist O(n),
da sie alle Knoten im Baum durchlaufen müssen.
Die Funktion insertNodeIntoAVLTree hat jedoch eine Zeitkomplexität von O(log n),
da sie nur den Pfad vom Wurzelknoten zum eingefügten Knoten durchläuft.
Die Funktion checkIfSubtree hat eine Zeitkomplexität von O(n + m),
wobei n und m die Anzahl der Knoten in den beiden Bäumen sind.
Sie muss beide Bäume durchlaufen, um sie in Listen zu konvertieren,
und dann die Listen durchlaufen, um zu überprüfen,
ob die eine Liste eine Teilmenge der anderen ist.
