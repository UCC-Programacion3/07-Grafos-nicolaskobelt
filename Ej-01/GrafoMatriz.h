#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H


template<class T>
class GrafoMatriz {
private:
    int **valores_arco;
    T *valores_nodo;
    bool **existe_arco;
    int size;

    bool inRange(int n){
        return n >= 0 && n < size;
    }

public:
    GrafoMatriz(int size);

    ~GrafoMatriz();

    // Metodos de Nodos

    void nodo_agregar(int n, T val);

    void nodo_remover(int n);

    void nodo_set_val(int n, T val);

    T nodo_get_val(int n2);


    // Metodos de Arcos

    void arco_agregar(int n1, int n2, int val);

    void arco_remover(int n1, int n2);

    void arco_set_val(int n1, int n2, int val);

    int arco_get_val(int n1, int n2);


    bool adyacentes(int n1, int n2);

    bool *vecinos(int n);

    bool esVacio();
};

template<class T>
GrafoMatriz<T>::GrafoMatriz(int size) {

    this->size = size;
    valores_nodo = new T*[size];
    valores_arco = new int *[size];
    existe_arco = new bool *[size];

    for (int i=0; i<size; i++) {

        valores_nodo[i] = NULL;
        valores_arco[i] = new int[size];
        existe_arco[i] = new bool[size];

        for (int j = 0; j < size; j++) {
            existe_arco[i][j] = false;
        }
    }
}

template<class T>
void GrafoMatriz<T>::nodo_agregar(int n, T val) {

    if (valores_nodo[n] == NULL && inRange(n)){
        valores_nodo[n] = new T;
        *valores_nodo[n] = val;
    }else
        throw 10;
}

template<class T>
void GrafoMatriz<T>::nodo_remover(int n) {
    if (valores_nodo[n] != NULL && inRange(n)){
        for (int i=0; i<size; i++){
            existe_arco[i][n] = false;
            existe_arco[n][i] = false;
        }
        delete valores_nodo[n];
        valores_nodo[n] = NULL;
    }
}

template<class T>
void GrafoMatriz<T>::nodo_set_val(int n, T val) {

    if(valores_nodo[n] == NULL && inRange(n))
        throw 34;

    *valores_nodo[n] = val;
}

template<class T>
T GrafoMatriz<T>::nodo_get_val(int n) {

    if(valores_nodo[n] == NULL)
        throw 34;

    return *valores_nodo[n];
}

template<class T>
void GrafoMatriz<T>::arco_agregar(int n1, int n2, int val) {

    if(valores_nodo[n1] == NULL)
        throw 1;
    if(valores_nodo[n2] == NULL)
        throw 2;
    if(existe_arco[n1][n2])
        throw 3;

    existe_arco[n1][n2] = true;
    valores_arco[n1][n2] = val;

}

template<class T>
void GrafoMatriz<T>::arco_remover(int n1, int n2) {

    if(existe_arco[n1][n2]){

        existe_arco[n1][n2] = false;

    }else
        throw 45;
}

template<class T>
void GrafoMatriz<T>::arco_set_val(int n1, int n2, int val) {

    if (existe_arco[n1][n2]){

        valores_arco[n1][n2]=val;

    }else
        throw 44;
}

template<class T>
int GrafoMatriz<T>::arco_get_val(int n1, int n2) {

    if (existe_arco[n1][n2]) {

        return valores_arco[n1][n2];

    }

    throw 44;
}


template<class T>
bool GrafoMatriz<T>::adyacentes(int n1, int n2) {

    return existe_arco[n1][n2] || existe_arco[n2][n1];
}

template<class T>
bool *GrafoMatriz<T>::vecinos(int n) {

    bool * resultado = new bool[size];

    for (int i = 0; i<size; i++){

            resultado[i] = false;
        if (existe_arco[n][i] || existe_arco[i][n])
            resultado[i] = true;
    }
    return resultado;
}

template<class T>
bool GrafoMatriz<T>::esVacio() {

    for (int i=0; i<size; i++){

        if (valores_nodo[i] != nullptr)
            return false;
    }
    return true;
}

template<class T>
GrafoMatriz<T>::~GrafoMatriz() {

    for (int i=0; i<size; i++) {

        if (valores_nodo[i] != nullptr)
            delete valores_nodo[i];
    }
}

#endif //GRAFOMATRIZ_H
