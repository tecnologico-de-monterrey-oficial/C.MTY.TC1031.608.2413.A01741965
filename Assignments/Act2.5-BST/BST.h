#ifndef BST_h
#define BST_h

#include "TNode.h"

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    int howManyChildren(TNode<T>* aux);
public:
    BST();
    void insert(T data);
    void print();
    bool find(T data);
    bool remove(T data);
    bool empty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
bool BST<T>::empty() {
    return root == nullptr;
}

template <class T>
int BST<T>::howManyChildren(TNode<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    } else {
        if (aux->left != nullptr && aux->right != nullptr) {
            return 2;
        } else {
            return 1;
        }
    }
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos que el arbol no este vacío
    if (!empty()) {
        // el arbol no está vacío
        // vamos a crear un apuntador auxiliar igual a root
        TNode<T>* aux = root;
        // iteramos mientras aux no sea nulos
        while (aux != nullptr) {
            // comparamos si data es menor que aux->data
            if (data < aux->data) {
                // data menor que aux->data
                // validamos si el apuntador left de aux es nulos
                if (aux->left == nullptr) {
                    // el apuntador left de aux si es nulo
                    // el apuntador left de aux apunta al nuevo elemento con data
                    aux->left = new TNode<T>(data);
                    // return
                    return;
                // else
                } else {
                    // el apuntador left de aux no es nulo
                    // recorremos aux a aux->left
                    aux = aux->left;
                }
                // endif
            // else
            } else {
                // data es mayor o igual a aux->data
                // validamos si el apuntador right de aux es nulos
                if (aux->right == nullptr) {
                    // el apuntador right de aux si es nulo
                    // apuntador right de aux apunta al nuevo elenmento con data
                    aux->right = new TNode<T>(data);
                    // return
                    return;
                // else
                } else {
                    // el apuntador ritgh de aux no es nulo
                    // recorremos aux a aux->right
                    aux = aux->right;
                // endif
                }
            // endif
            }
        // end while
        }
    // else de empty
    } else {
        // el arbol está vacío
        // hacemos root al nuevo elemento con dadt
        root = new TNode<T>(data);
    // endif
    }
}

template <class T>
bool BST<T>::find(T data) {
    // creamos una apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // iteramos mientras aux sea diferente de nulos
    while (aux != nullptr) {
        //validamos si el valor de aux es igual al valor buscado
        if (aux->data == data) {
            // si es igual
            // regresamos true
            return true;
        // else
        } else {
            // no es igual
            // comparamos si el valor buscado es menor al valor de aux
            // if (data < aux->data) {
            //     // si es menor
            //     // recorremos aux al lado izquierdo
            //     aux = aux->left;
            // // else
            // } else {
            //     // es mayor o igual
            //     // recorremos aux al lado derecho
            //     aux = aux->right;
            // // endif
            // }
            // validamos hacia donde recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
        // endif
        }
    // endiwhile
    }
    return false;
}

template <class T>
bool BST<T>::remove(T data) {
    // validamos que el bst no este vacío
    if (!empty()) {
        // el bst no está vacío
        // validamos si el valor a borrar es el valor de root
        if (root->data == data) {
            // sí vamos a borrar root
            // validamos cuantos hijos tiene
            switch (howManyChildren(root)) {
                // no tiene hijos
                case 0:
                    // Creamos un apuntador auxiliar igual a root
                    TNode<T>* aux = root;
                    // hacemos root igual a nulos
                    root = nullptr;
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                // tiene 1 hijo
                case 1:
                    // creamos un apuntador auxiliar igual a root
                    TNode<T>* aux = root;
                    // validamos de que lado está el hijo
                    if (root->left != nullptr) {
                        // está del lado izquierdo
                        // apuntamos root al lado izquierdo de root
                        root = root->left;
                    } else {
                        // está del lado derecho
                        // apuntamos root al lado derecho de root
                        root = root->right;
                    }
                    // borramos aux
                    delete aux;
                    // regresamos true
                    return true;
                // tiene 2 hijos
                case 2:
                    // pendiente
                    break;
            }
        } else {
            // no es root el valor a borrar
            // creamos un apuntador aux papa igual a root
            TNode<T>* aux_papa = root;
            // creamos un apuntador aux igual a root
            TNode<T>* aux = root;
            // iteramos mientras aux sea diferente de nulos
            while (aux != nullptr) {
                // validamos si el valor a borrar es menor que el valor de aux
                if (data < aux->data) {
                    // sí es menor
                    // recorremos aux a la izquierda de aux
                    aux_papa = aux;
                    aux = aux->left;
                } else {
                    // es mayor o igual
                    // recorremos aux a la derecha de aux
                    aux_papa = aux;
                    aux = aux->right;
                }
                // validamos si el valor de aux es el valor a borrar
                if (aux != nullptr && aux->data == data) {
                    // sí es el valor a borrar
                    // validamos cuantos hijos tiene
                    switch (howManyChildren(aux)) {
                        // No tiene hijos
                        case 0:
                            // validamos si el valor de aux es menor al valor de aux papa
                            if (aux->data < aux_papa->data) {
                                // sí es menor
                                // el apuntador de lado izquierdo de aux papa es nulos
                                aux_papa->left = nullptr;
                            } else {
                                // no es menor
                                // el apuntador de lado derecho de aux papa es nulos
                                aux_papa->right = nullptr;
                            }
                            // borramos aux
                            delete aux;
                            // regresamos true
                            return true;
                        // Tiene 1 hijo
                        case 1:
                            // validamos si el valor de aux es menor al valor de aux papa
                            if (aux->data < aux_papa->data) {
                                // sí es menor
                                // validamos si el valor del lado izquierdo de aux es nulos
                                if (aux->left != nullptr) {
                                    // el lado izquierdo de aux es nulos (hijo del lado derecho)
                                    // el apuntador del lado izquierdo de aux papa es igual al apuntador de lado derecho de aux
                                    aux_papa->left = aux->left;
                                } else {
                                    // el lado derecho de aux es nulos (hijo del lado izquiedo)
                                    // el apuntador del lado izquierdo de aux papa es igual al apuntador de lado izquierdo de aux
                                    aux_papa->left = aux->right;
                                }
                            } else {
                                // es mayor o igual
                                // validamos si el valor del lado izquierdo de aux es nulos
                                if (aux->left != nullptr) {
                                    // el lado izquierdo de aux es nulos (hijo del lado derecho)
                                    // el apuntador del lado derecho de aux papa es igual al apuntador de lado derecho de aux
                                    aux_papa->right = aux->left;
                                } else {
                                    // el lado derecho de aux es nulos (hijo del lado izquiedo)
                                    // el apuntador del lado derecho de aux papa es igual al apuntador de lado izquierdo de aux
                                    aux_papa->right = aux->right;
                                }
                            }
                            // boramos aux
                            delete aux;
                            // regresamos true
                            return true;
                        // tiene 2 hijos
                        case 2:
                            // pendiente
                            break;
                    }
                }
            }
        }
    }
    return false;
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!empty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 




#endif /* BST_h */