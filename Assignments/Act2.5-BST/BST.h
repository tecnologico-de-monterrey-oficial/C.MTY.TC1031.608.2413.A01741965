#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <queue>
#include <stack>



template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    int howManyChildren(TNode<T>* aux);
    void preOrder(TNode<T>* aux);
    void inOrder(TNode<T>* aux);
    void postOrder(TNode<T>* aux);
    void levelByLevel(TNode<T>* aux);
    int heightAux(TNode<T>* aux);
    
public:
    BST();
    void insert(T data);
    void print();
    bool find(T data);
    bool remove(T data);
    bool empty();
    void visit(int order);
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
    TNode<T>* getRoot() { return root; }
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
            data < aux->data ? aux = aux->left : aux = aux->right;
        // endif
        }
    // endwhile
    }
    return false;
}




template <class T>
bool BST<T>::remove(T data) {
    // validamos que el bst no este vacío
    if (!empty()) {
        // -> el bst no está vacío
        // validamos si el valor a borrar es el valor de root
        if (data == root->data) {
            // -> sí vamos a borrar root
            // validamos cuantos hijos tiene
            int children = howManyChildren(root);
            // hacemos un switch con la cantidad de hijos
            switch (children) {
                // no tiene hijos
                case 0: {
                    // Creamos un apuntador auxiliar igual a root
                    TNode<T>* aux = root;
                    // hacemos root igual a nulos
                    root = nullptr;
                    // Borramos aux
                    delete aux;
                    // Regresamos true
                    return true;
                }
                break;
                // tiene 1 hijo
                case 1: {
                    // creamos un apuntador auxiliar igual a root
                    TNode<T>* aux = root;
                    // validamos de que lado está el hijo
                    if (aux->left != nullptr) {
                        // -> está del lado izquierdo
                        // apuntamos root al lado izquierdo de root
                        root = root->left;
                    // else
                    } else {
                        // -> está del lado derecho
                        // apuntamos root al lado derecho de root
                        root = root->right;
                    }
                    // borramos aux
                    delete aux;
                    // regresamos true
                    return true;
                }
                break;
                // tiene 2 hijos
                case 2: {
                    // Creamos un apuntador auxRemove igual a root
                    TNode<T>* auxRemove = root;
                    // creamos un apuntador aux igual al apuntador del lado izquierdo de auxRemove
                    TNode<T>* aux = auxRemove->left;
                    // Validamos si el apuntador de aux del lado derecho es nulo
                    if (aux->right == nullptr) {
                        // -> si es nulo, ya encontramos el más grande del lado izquierdo
                        // hacemos que el valor de auxRemove sea igual al valor de aux
                        auxRemove->data = aux->data;
                        // asignamos al apuntador del lado izquierrdo de auxRemove el apuntador del lado izquierdo de aux
                        auxRemove->left = aux->left;
                        // borramos aux
                        delete aux;
                        // return true
                        return true;
                    // else
                    } else {
                        // -> no es nulo, aun no encontramos el más grande del lado izquierdo
                        // Creamos un apuntador auxDad igual a aux
                        TNode<T>* auxDad = aux;
                        // asignamos a aux el valor del apuntador del lado derecho de aux
                        aux = aux->right;
                        // iteramos mientras el apuntador del lado derecho de aux no sea nulos
                        while (aux->right != nullptr) {
                            // recorremos auxDad a aux
                            auxDad = aux;
                            // recorremos aux al apuntador del lado derecho de aux
                            aux = aux->right;
                        // endwhile
                        }
                        // hacemos que el valor de auxRemove sea igual al valor de aux
                        auxRemove->data = aux->data;
                        // asignamos al apuntador del lado derecho de auxDad el apuntador del lado izquierdo de aux
                        auxDad->right = aux->left;
                        // boramos aux
                        delete aux;
                        // regresamos true
                        return true;
                    // endif
                    }
                }
                break;
            default:
                break;
            // endswitch
            }
        // else
        } else {
            // -> no es root el valor a borrar
            // creamos un apuntador aux papa igual a root
            TNode<T>* auxDad = root;
            // creamos un apuntador aux igual a root
            TNode<T>* aux = root;
            // iteramos mientras aux sea diferente de nulos
            while (aux != nullptr) {
                // validamos si el valor a borrar es menor que el valor de aux
                if (data < aux->data) {
                    // -> sí es menor
                    // recorremos aux a la izquierda de aux
                    aux = aux->left;
                // else
                } else {
                    // -> es mayor o igual
                    // recorremos aux a la derecha de aux
                    aux = aux->right;
                // endif
                }
                // validamos si aux es diferente de nulos
                if (aux != nullptr) {
                    // validamos si el valor de aux es el valor a borrar
                    if (data == aux->data) {
                        // -> sí es el valor a borrar
                        // validamos cuantos hijos tiene
                        int children = howManyChildren(aux);
                        // hacemos un switch con los hijos
                        switch (children) {
                        case 0: {
                        // -> No tiene hijos
                            // validamos si el valor de aux es menor al valor de aux papa
                            if (aux->data < auxDad->data) {
                                // -> sí es menor
                                // el apuntador de lado izquierdo de aux papa es nulos
                                auxDad->left = nullptr;
                            // else
                            } else {
                                // -> no es menor
                                // el apuntador de lado derecho de aux papa es nulos
                                auxDad->right = nullptr;
                            //endif
                            }
                            // borramos aux
                            delete aux;
                            // regresamos true
                            return true;
                        }
                        break;
                        // Tiene 1 hijo
                        case 1: {
                            // validamos si el valor de aux es menor al valor de aux papa
                            if (aux->data < auxDad->data) {
                                // -> sí es menor
                                // validamos si el valor del lado izquierdo de aux es nulos
                                if (aux->left == nullptr) {
                                    // -> el lado izquierdo de aux es nulos (hijo del lado derecho)
                                    // el apuntador del lado izquierdo de aux papa es igual al apuntador de lado derecho de aux
                                    auxDad->left = aux->right;
                                // else    
                                } else {
                                    // ->el lado derecho de aux es nulos (hijo del lado izquiedo)
                                    // el apuntador del lado izquierdo de aux papa es igual al apuntador de lado izquierdo de aux
                                    auxDad->left = aux->left;
                                // endif
                                }
                            // else
                            } else {
                                // -> es mayor o igual
                                // validamos si el valor del lado izquierdo de aux es nulos
                                if (aux->left == nullptr) {
                                    // -> el lado izquierdo de aux es nulos (hijo del lado derecho)
                                    // el apuntador del lado derecho de aux papa es igual al apuntador de lado derecho de aux
                                    auxDad->right = aux->right;
                                // else    
                                } else {
                                    // -> el lado derecho de aux es nulos (hijo del lado izquierdo)
                                    // el apuntador del lado derecho de aux papa es igual al apuntador de lado izquierdo de aux
                                    auxDad->right = aux->left;
                                // endif
                                }
                            // endif
                            }
                            // boramos aux
                            delete aux;
                            // regresamos true
                            return true;
                        }
                        break;
                        // tiene 2 hijos
                        case 2: {
                            // Creamos un apuntador auxRemove igual a aux
                            TNode<T>* auxRemove = aux;
                            // Hacemos aux igual al apuntador del lado izquierdo de auxRemove
                            aux = auxRemove->left;
                            // Validamos si el apuntador de aux del lado derecho es nulo
                            if (aux->right == nullptr) {
                                // -> si es nulo, ya encontramos el más grande del lado izquierdo
                                // hacemos que el valor de auxRemove sea igual al valor de aux
                                auxRemove->data = aux->data;
                                // asignamos al apuntador del lado izquierdo de auxRemove el apuntador del lado izquierdo de aux
                                auxRemove->left = aux->left;
                                // borramos aux
                                delete aux;
                                // return true
                                return true;
                            // else
                            } else {
                                // -> no es nulo, aun no encontramos el más grande del lado izquierdo
                                // Creamos un apuntador auxDad igual a aux
                                TNode<T>* auxDad = aux;
                                // asignamos a aux el valor del apuntador del lado derecho de aux
                                aux = aux->right;
                                // iteramos mientras el apuntador del lado derecho de aux no sea nulos
                                while (aux->right != nullptr) {
                                    // recorremos auxDad a aux
                                    auxDad = aux;
                                    // recorremos aux al apuntador del lado derecho de aux
                                    aux = aux->right;
                                // endwhile
                                }
                                // hacemos que el valor de auxRemove sea igual al valor de aux
                                auxRemove->data = aux->data;
                                // asignamos al apuntador del lado derecho de auxDad el apuntador del lado izquierdo de aux
                                auxDad->right = aux->left;
                                // boramos aux
                                delete aux;
                                // regresamos true
                                return true;
                            // endif
                            }
                        }
                        break;                        
                        default:
                            break;
                        // endswitch
                        }
                    // else
                    } else {
                        // -> no es el valor a borrar
                        // hacemos aux papa igual a aux
                        auxDad = aux;
                    // endif
                    }
                // endif -> aux es diferente de nulos
                }
            // endwhile
            }
            // -> no encontramos el valor a borrar
            // regresamos false
            return false;
        // endif
        }
        return false;
    // else -> si el bst está vacío
    } else {
        // return false
        return false;
    // endif
    }
}

template <class T>
void BST<T>::preOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Visita el nodo raíz
        cout << aux->data << " ";
        // hago el preOrder del sub arbol izquierdo
        preOrder(aux->left);
        // hago el preOrder del sub arbol derecho
        preOrder(aux->right);
    }
}

template <class T>
void BST<T>::inOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // hago el preOrder del sub arbol izquierdo
        inOrder(aux->left);
        // Visita el nodo raíz
        cout << aux->data << " ";
        // hago el preOrder del sub arbol derecho
        inOrder(aux->right);
    }
}

template <class T>
void BST<T>::postOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // hago el preOrder del sub arbol izquierdo
        postOrder(aux->left);
        // hago el preOrder del sub arbol derecho
        postOrder(aux->right);
        // Visita el nodo raíz
        cout << aux->data << " ";
    }
}

template <class T>
void BST<T>::levelByLevel(TNode<T>* aux) {
    //validamo si que el arbol no este vacío
    if (!empty()) {
        // creamos una fila de tipo apuntador de tipo TNode<T> 
        queue< TNode<T>* > q;
        // agregamos a la fila aux
        q.push(aux);
        // iteramos mientras la fila no este vacía
        while (!q.empty()) {
            // imprimimos el primer elemento de la fila
            aux = q.front();
            cout << aux->data << " ";
            // sacamos el primer elemento de la fila
            q.pop();
            // agreamos los hijos del elemento que acabamos de sacar de la fila si es que existen
            if (aux->left != nullptr) {
                q.push(aux->left);
            }
            if (aux->right != nullptr) {
                q.push(aux->right);
            }
        // endwhile
        }
        // imprimimos un salto de renglón
        cout << endl;
    }
}
    
    

template <class T>
void BST<T>::visit(int order) {
    switch (order)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    case 4:
        levelByLevel(root);
        break;
    
    default:
        break;
    }
    cout << endl;
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

template<class T>
int BST<T>::height() {
    return heightAux(root);
}

template<class T>
int BST<T>::heightAux(TNode<T>* aux) {
    if (aux == nullptr) {
        return 0;
    } else {
        int left = heightAux(aux->left);
        int right = heightAux(aux->right);
        return left > right ? left + 1 : right + 1;
    }
}

template<class T>
void BST<T>::ancestors(T data) {
    TNode<T>* aux = root;
    stack<T> s;
    while (aux != nullptr) {
        if (data == aux->data) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
            return;
        } else {
            s.push(aux->data);
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    cout << "No se encontró el dato" << endl;
}
    


template<class T>
int BST<T>::whatLevelAmI(T data) {
    TNode<T>* aux = root;
    int level = 0;
    while (aux != nullptr) {
        if (data == aux->data) {
            return level;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
            level++;
        }
    }
    return -1;
}


#endif /* BST_h */