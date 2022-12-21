#include <iostream>
#include "List.h"
#include "OnlyNumbers_Validation.h"

using namespace std;
/**
 * @brief Metodo constructor de List con sus atributos inicializados NULL
 *
 *
 */
List::List()
{
    first_node = NULL;
    last_node = NULL;
}
/**
 * @brief Metodo constructor de List
 *@param *first_node puntero por la cabeza
 *@param *last_node puntero por la cola
 *
 */
List::List(Node* firstNode, Node* lastNode)
{
    first_node = firstNode;
    last_node = lastNode;
}

/**
 * @brief metodo getter del nodo por la cabeza
 *
 *
 */
Node* List::getFirstNode()
{
    return first_node;
}

/**
 * @brief metodo getter del nodo por la cola
 *
 *
 */
Node* List::getLastNode()
{
    return last_node;
}

/**
 * @brief metodo setter del nodo por la cabeza
 *
 *
 */
void List::setFirstNode(Node* firstNode)
{
    first_node = firstNode;
}

/**
 * @brief metodo setter del nodo por la cola
 *
 *
 */
void List::setLastNode(Node* lastNode)
{
    last_node = lastNode;
}

/**
 * @brief metodo verifica si la lista esta o no vacia
 *@param List_ la lista a evaluar
 *
 */
bool List::verify(List* List_)
{
    if (List_->getFirstNode() == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "\n\t    La lista esta vacia\n" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return false;
    }
    else {
        return true;
    }
}

/**
 * @brief metodo almacena espacion de memoria y crea un nuevo nodo en la lista
 *@param data es el valor que va a almacenar el nodo creado
 *
 */
Node* List::createNode(int data)
{
    Node* node_ = new Node(); //Reserva memoria para 1 nodo
    if (node_ != NULL) {
        node_->setData(data);
        node_->setNext(NULL);
        cout << "\n\t   Dato: " << node_->getData();
    }
    return node_;
}

/**
 * @brief metodo que crea un nuevo nodo al final de la lista
 *@param List_ la lista que vamos a recorrer
 *@param data es el valor que va a almacenar el nodo creado
 *
 */
List* List::add_at_the_end(List* List_, int data) //Final
{
    Node* node_ = new Node(data, NULL);
    if (node_ != NULL)
    {
        if (List_->getFirstNode() != NULL) {
            List_->getLastNode()->setNext(node_);
            List_->setLastNode(node_);
            cout << "\n\t   Dato ingresado : " << node_->getData() << endl;
            return List_;
        }
        else { //Lista esta vacia
            List* empty_list = new List(NULL, NULL);
            empty_list->setFirstNode(node_);
            empty_list->setLastNode(node_);
            cout << "\n\t   Dato ingresado : " << node_->getData() << endl;
            return empty_list;
        }
    }
    else {
        return NULL;
    }
}

/**
 * @brief metodo que realiza operaciones matematicas con los valores que almacenan los nodos de la lista
 *@param List_ la lista que vamos a recorrer
 *
 */
void List::operations(List* List_)
{
    Node* node_ = List_->getFirstNode();
    if (node_ != NULL)
    {
        int sum = 0;
        int length = size_List(List_);
        int counter = 0;
        float average;
        while (node_ != NULL)
        {
            sum = sum + node_->getData();
            node_ = node_->getNext();
            counter++;
        }
        printf("Suma de los elementos :%d\n", sum);
        average = (float)sum / (float)counter;
        printf("El promedio es:%f\n", average);
        int* chain = NULL;
        chain = new int[counter];
        counter = 0;
        node_ = List_->getFirstNode();
        while (node_ != NULL)
        {
            chain[counter] = node_->getData();
            node_ = node_->getNext();
            counter++;
        }
        int new_counter = counter;
        int s = 0, m = 0, a;
        //m = s; 

        for (int i = 0; i < new_counter; i++) {
            s = 0;
            for (int j = 0; j < new_counter; j++) {
                if (chain[i] == chain[j] && i != j)
                {
                    s = s + 1;
                }
            }
            if (s >= m) {
                m = s;
                a = i;
            }
        }

        cout << "la moda es: " << chain[a] << " y tiene " << m + 1 << " repeticiones" << endl;
    }

    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "\n\t    La lista esta vacia\n" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    }
}

/**
 * @brief metodo que crea un nuevo nodo al inicio de la lista
 *@param List_ la lista que vamos a recorrer
 *@param data es el valor que va a almacenar el nodo creado
 *
 */

List* List::add_to_start(List* List_, int dato)
{
    Node* node_ = new Node(dato, NULL);
    if (node_ != NULL)
    {
        if (List_->getFirstNode() != NULL) {
            node_->setNext(List_->getFirstNode());
            List_->setFirstNode(node_);
            cout << "\n\t   Dato ingresado : " << node_->getData() << endl;
            return List_;
        }
        else {
            List* active_list = new List(NULL, NULL);
            active_list->setFirstNode(node_);
            active_list->setLastNode(node_);
            cout << "\n\t   Dato ingresado : " << node_->getData() << endl;
            return active_list;
        }
    }
    else {
        return NULL;
    }
}

/**
 * @brief metodo que imprime los nodos y los valores de la lista
 *@param List_ la lista que vamos a recorrer
 *
 *
 */
void List::print(List* List_)
{
    int counter = 1;
    if (verify(List_)) {
        Node* node_ = List_->getFirstNode();
        do {
            cout << "\n\t\tNodo " << counter << ": " << node_->getData() << endl;
            node_ = node_->getNext(); //Instruccion para moverme al siguiente
            counter++;
        } while (node_ != NULL);
    }
}

/**
 * @brief metodo que elimina el valor de un nodo
 *@param List_ la lista que vamos a recorrer
 *
 *
 */
List* List::deleteNode(List* List_)
{
    int option;
    if (verify(List_))
    {
        Node* node_ = List_->getFirstNode();
        cout << "\n\tSe eliminara el dato -> " << node_->getData() << ". Desea continuar? \n\t1-SI / 0-NO: ";
        cin >> option;
        if (option == 1)
        {
            List_->setFirstNode(node_->getNext());
            delete node_;
            cout << "\n\tSe elimino el nodo" << endl;
            if (List_->getFirstNode() == NULL)
            {
                delete List_;
                //L = NULL;
                List_->setLastNode(NULL);
                cout << "\n\tSe elimino el ultimo elemento de la lista." << endl;
                return List_;
            }
        }
    }
    return List_;
}

/**
 * @brief metodo que busca entre una lista con desorden
 *@param List_ la lista que vamos a recorrer
 *@param searcher el valor que buscamos
 *
 */
Node* List::searchDisorder(List* List_, int searcher)
{
    Node* node_ = NULL;
    if (List_->getFirstNode() != NULL)
    {
        node_ = List_->getFirstNode();
        while (node_ != NULL && node_->getData() != searcher)
        {
            node_ = node_->getNext();
        }
    }
    return node_;
}

/**
 * @brief metodo que busca un dato almacenado en un nodo de la lista
 *@param List_ la lista que vamos a recorrer
 *@param searcher es el valor que buscamos
 *
 */
void List::search(List* List_, int searcher)
{
    Node* node_ = new Node();
    node_ = List_->searchDisorder(List_, searcher);
    if (node_ != NULL)
    {
        cout << "\n\t> Dato encontrado\n" << endl;
    }
    else
    {
        cout << "\n\t> Dato no encontrado\n" << endl;
    }
    cout << endl;
}

/**
 * @brief metodo que muestra el tamanio de la lista
 *@param List_ la lista que vamos a recorrer
 *
 *
 */
int List::size_List(List* List_)
{
    int counter = 1;
    if (List_->getFirstNode() != NULL) {
        Node* node_ = List_->getFirstNode();
        do {
            node_ = node_->getNext();
            counter++;
        } while (node_ != NULL);
        return counter;
    }
    else {
        return 0;
    }
}

/**
 * @brief metodo que a�ade un nodo antes de otro elegido por el usuario
 *@param List_ la lista que vamos a recorrer
 *@param data es el valor que va a almacenar el nodo
 *@param counter recorre los limites de la lista
 *
 */
List* List::addBefore(List* List_, int data, int counter)
{
    Node* node_ = new Node(data, NULL);
    if (counter <= List_->size_List(List_) - 2 || counter == 0)
    {
        if (List_->size_List(List_) != 0 && counter > 0) {
            if (counter == List_->size_List(List_) - 1)
            {
                List_ = List_->add_at_the_end(List_, data);
                return List_;
            }
            else {
                int i = 1;
                Node* aux_node = List_->getFirstNode();
                while (i != counter) {
                    aux_node = aux_node->getNext();
                    i++;
                }
                node_->setNext(aux_node->getNext());
                aux_node->setNext(node_);
                cout << "\n\t   Dato ingresado: " << node_->getData() << endl;
            }
        }
        else {
            cout << "\n\t   Se creara en el primer nodo" << endl;
            List_ = List_->add_to_start(List_, data);
            return List_;
        }
    }
    else {
        cout << "\n\t   El nodo no existe" << endl;
    }
    return List_;
}


/**
 * @brief metodo que a�ade un nodo despues de otro elegido por el usuario
 *@param List_ la lista que vamos a recorrer
 *@param data es el valor que va a almacenar el nodo
 *@param counter recorre los limites de la lista
 *
 */
List* List::addAfter(List* List_, int data, int counter)
{
    Node* node_ = new Node(data, NULL);
    if (counter <= List_->size_List(List_) - 1 || counter == 0)
    {
        if (List_->size_List(List_) != 0 && counter > 0) {
            if (counter == List_->size_List(List_) - 1)
            {
                List_ = List_->add_at_the_end(List_, data);
                return List_;
            }
            else {
                int i = 1;
                Node* aux_node = List_->getFirstNode();
                while (i != counter) {
                    aux_node = aux_node->getNext();
                    i++;
                }
                node_->setNext(aux_node->getNext());
                aux_node->setNext(node_);
                cout << "\n\t   Dato ingresado: " << node_->getData() << endl;
            }
        }
        else {
            cout << "\n\t   Se creara en el primer nodo" << endl;
            List_ = List_->add_to_start(List_, data);
            return List_;
        }
    }
    else {
        cout << "\n\t   El nodo no existe" << endl;
    }
    return List_;
}

/**
 * @brief metodo que elimina el ultimo nodo de la lista
 *@param List_ la lista que vamos a recorrer
 *
 */
List* List::deleteLast(List* List_)
{
    int option;
    if (verify(List_))
    {
        Node* node_ = List_->getLastNode();
        cout << "\n\tSe eliminara el dato -> " << node_->getData() << ". Desea continuar? \n\t1-SI / 0-NO: ";
        cin >> option;
        if (option == 1)
        {
            Node* aux_node = NULL;
            node_ = List_->getFirstNode();
            while (node_->getNext() != NULL) {
                aux_node = node_;
                node_ = node_->getNext();
            }
            if (aux_node == NULL)
            {
                List_->setFirstNode(node_->getNext());
            }
            else
            {
                aux_node->setNext(NULL);
                List_->setLastNode(aux_node);
                delete node_;
            }
            if (List_->getFirstNode() == NULL)
            {
                delete List_;
                List_->setLastNode(NULL);
                cout << "\n\tSe elimino el ultimo elemento en la lista." << endl;
                return List_;
            }
            cout << "\n\tSe elimino el nodo" << endl;
        }
    }
    return List_;
}

/**
 * @brief metodo que elimina un nodo X elegido por el usuario de la lista
 *@param List_ la lista que vamos a recorrer
 *
 */
List* List::delete_X_node(List* List_, int counter)
{
    int option;
    Node* node_ = List_->getFirstNode();
    Node* aux_node = NULL;
    if (verify(List_)) {
        if (counter == 1)
        {
            List_ = List_->deleteNode(List_);
        }
        else if (counter == List_->size_List(List_) - 1)
        {
            List_ = List_->deleteLast(List_);
        }
        else if (counter >= List_->size_List(List_) || counter < 1)
        {
            cout << "\n\tEl nodo no existe" << endl;
        }
        else if (node_ != NULL)
        {
            int i = 1;
            while (i != counter)
            {
                aux_node = node_;
                node_ = node_->getNext();
                i++;
            }
            cout << "\n\tSe eliminara el dato -> " << node_->getData() << ". Desea continuar? \n\t1-SI / 0-NO: ";
            cin >> option;
            if (option == 1)
            {
                if (node_ != NULL)
                {
                    aux_node->setNext(node_->getNext());
                }
                delete node_;
                cout << "\n\tSe elimino el nodo" << endl;
            }
        }
    }
    return List_;
}


/**
 * @brief metodo que elimina un nodo ubicado despues de otro elegido por el usuario
 *@param List_ la lista que vamos a recorrer
 *
 */
List* List::delete_after_to(List* List_)
{
    Node* node_ = List_->getFirstNode();
    Node* aux_node;
    int counter = 1, selected_node, option = 0;
    int lenght = size_List(List_);
    if (verify(List_))
    {
        List_->print(List_);
        cout << "\n\tIngrese el nodo: ";
        cin >> selected_node;

        if (selected_node == lenght - 1 || selected_node < 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "\n\tNo existe nodo despues del seleccionado" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else {
            if (selected_node == lenght - 2)
            {
                List_ = List_->deleteLast(List_);
            }
            else {
                while (counter != selected_node)
                {
                    aux_node = node_;
                    node_ = node_->getNext();
                    counter++;
                }
                aux_node = node_;
                node_ = node_->getNext();
                cout << "\n\tSe eliminara el dato -> " << node_->getData() << ". Desea continuar? \n\t1-SI / 0-NO: ";
                cin >> option;
                if (option == 1)
                {
                    aux_node->setNext(node_->getNext());
                    delete node_;
                    cout << "\n\tSe elimino el nodo" << endl;
                }
            }
        }
    }
    return List_;
}

/**
 * @brief metodo que elimina un nodo ubicado antes de otro elegido por el usuario
 *@param List_ la lista que vamos a recorrer
 *
 */
List* List::delete_before_to(List* List_)
{
    Node* node_ = List_->getFirstNode();
    Node* aux_node;
    int counter = 1, selected_node, option = 0;
    int longitud = size_List(List_);
    if (verify(List_))
    {
        List_->print(List_);
        cout << "\n\tIngrese el nodo: ";
        cin >> selected_node;

        if (selected_node > longitud - 1 || selected_node <= 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "\n\tNo existe nodo antes del seleccionado o excedio el tamanio de la lista" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else {
            if (selected_node == 2)
            {
                List_ = List_->deleteNode(List_);
            }
            else {
                while (counter != selected_node - 2)
                {
                    aux_node = node_;
                    node_ = node_->getNext();
                    counter++;
                }
                aux_node = node_;
                node_ = node_->getNext();
                cout << "\n\tSe eliminara el dato -> " << node_->getData() << ". Desea continuar? \n\t1-SI / 0-NO: ";
                cin >> option;
                if (option == 1)
                {
                    aux_node->setNext(node_->getNext());
                    delete node_;
                    cout << "\n\tSe elimino el nodo" << endl;
                }
            }
        }
    }
    return List_;
}
 void List::MaximComunDivisor(List* List_)
{
     Node* node_ = List_->getFirstNode();
     int a, b, c;
     if (verify(List_))
    {
         while (node_ != NULL)
         {
            a = node_->getData();
            node_ = node_->getNext();
            b = node_->getData();
            node_ = node_->getNext();
            while (b != 0)
            {
                 c = a % b;
                 a = b;
                b = c;
            }
            cout << "\n\tEl MCD es: " << a << endl;
         }
    }
 }
//function to find least common multiple using recursion 
int lcm(int a, int b)
{
    static int multiple = 0;
    multiple += b;
    if ((multiple % a == 0) && (multiple % b == 0))
    {
        return multiple;
    }
    else
    {
        return lcm(a, b);
    }
}
 void List::MinimComunMult(List* List_)
{
     Node* node_ = List_->getFirstNode();
     int a, b, c;
     if (verify(List_))
    {
         while (node_ != NULL)
         {
            a = node_->getData();
            node_ = node_->getNext();
            b = node_->getData();
            node_ = node_->getNext();
            c = lcm(a, b);
            cout << "\n\tEl MCM es: " << c << endl;
         }
    }
 }

//funtion the sum of the digits of a number of each node of the list 
 void List::sum_digits(List* List_)
{
    Node* node_ = List_->getFirstNode();
    int sum = 0, aux = 0;
    if (verify(List_))
    {
        while (node_ != NULL)
        {
            aux = node_->getData();
            while (aux != 0)
            {
                sum += aux % 10;
                aux /= 10;
            }
            while (sum > 9)
            {
                aux = sum;
                sum = 0;
                while (aux != 0)
                {
                    sum += aux % 10;
                    aux /= 10;
                }
            }
            cout << "\n\tLa suma de los digitos del nodo " << node_->getData() << " es: " << sum << endl;
            sum = 0;
            node_ = node_->getNext();
        
        }
    }
}
// implementar una funcion para hacer una busqueda binaria en una lista ordenada

//implementar una funcion para ordenar la lista de menor a mayor 
    void List::sort(List* List_)
{
    Node* node_ = List_->getFirstNode();
    Node* aux_node;
    int aux = 0;
    if (verify(List_))
    {
        while (node_ != NULL)
        {
            aux_node = node_->getNext();
            while (aux_node != NULL)
            {
                if (node_->getData() > aux_node->getData())
                {
                    aux = node_->getData();
                    node_->setData(aux_node->getData());
                    aux_node->setData(aux);
                }
                aux_node = aux_node->getNext();
            }
            node_ = node_->getNext();
        }
    }


}
void List::binary_search(List* List_) {
  int data = 0;
  char ar_nums[5];
  OnlyNumbers_Validation obj_validate;
  sort(List_);
  cout << "\n\tIngrese el dato a buscar: ";
  obj_validate.natural_numbers(ar_nums);
  data = atoi(ar_nums);
  int position = 0;
  Node* result = binarySearch(List_->getFirstNode(), data, position);
  if (result != NULL) {
    cout << "\n\tEl dato se encuentra en la posicion " << position+1 << " de la lista" << endl;
  } else {
    cout << "\n\tEl dato no se encuentra en la lista" << endl;
  }
}

/*
void List::binary_search(List* List_)
{
    
    int data2  = 0;
    char ar_nums[5];
    OnlyNumbers_Validation obj_validate;
     sort(List_);
    cout << "\n\tIngrese el dato a buscar: ";
    obj_validate.natural_numbers(ar_nums);
     data2 = atoi(ar_nums);
    Node* result = binarySearch(List_->getFirstNode(), data2);
    if (result != NULL) {
      cout << "\n\tEl dato se encuentra en la lista" << endl;
    } else {
      cout << "\n\tEl dato no se encuentra en la lista" << endl;
    }
}
*/
/*
Node* List::binarySearch(Node* head, int data2) {
  Node* left = head;
  Node* right = NULL;
  int counter = 0;

  while (left != right) {
    Node* mid = left;
    int steps = 0;
    while (mid->getNext() != right && steps < (counter / 2)) {
      mid = mid->getNext();
      steps++;
    }
    if (mid->getData() < data2) {
      left = mid->getNext();
    } else {
      right = mid;
    }
  }
  if (left->getData() == data2) {
    return left;
  }
  return NULL;
}
*/

Node* List::binarySearch(Node* head, int data, int& position) {
  Node* left = head;
  Node* right = NULL;
  while (left != right) {
    Node* mid = left;
    int steps = 0;
    while (mid->getNext() != right && steps < (position / 2)) {
      mid = mid->getNext();
      steps++;
    }
    if (mid->getData() < data) {
      left = mid->getNext();
      position = position + steps + 1;
    } else {
      right = mid;
    }
  }
  if (left->getData() == data) {
    return left;
  }
  return NULL;
}


void List::sequential_search(List* List_) {
  int data = 0;
  char ar_nums[5];
  OnlyNumbers_Validation obj_validate;
  cout << "\n\tIngrese el dato a buscar: ";
  obj_validate.natural_numbers(ar_nums);
  data = atoi(ar_nums);
  int position = 0;
  Node* current = List_->getFirstNode();
  while (current != NULL) {
    if (current->getData() == data) {
      cout << "\n\tEl dato se encuentra en la posicion " << position+1 << " de la lista" << endl;
      return;
    }
    current = current->getNext();
    position++;
  }
  cout << "\n\tEl dato no se encuentra en la lista" << endl;
}



Node* List::sequentialSearch(Node* head, int data) {
  Node* current = head;
  while (current != NULL) {
    if (current->getData() == data) {
      return current;
    }
    current = current->getNext();
  }
  return NULL;
}

void List::hashInsert(int data) {
  int index = hashFunction(data); // Calcular el índice en el que debe insertarse el elemento
  Node* newNode = new Node(data); // Crear un nuevo nodo para el elemento
  newNode->setNext(hashTable[index]); // Enlazar el nuevo nodo con el primer elemento de la lista enlazada en la celda
  hashTable[index] = newNode; // Establecer el nuevo nodo como el primer elemento de la lista enlazada
}

void List::hash_insert_all(List* List_) {
  Node* current = List_->getFirstNode(); // Obtener el primer elemento de la lista enlazada
  while (current != NULL) { // Recorrer la lista enlazada
    hashInsert(current->getData()); // Insertar el elemento en la tabla hash
    current = current->getNext(); // Avanzar al siguiente elemento
  }
}

int List::hashFunction(int data) {
    return data % TABLE_SIZE;
  }

 Node* List::hashSearch(int data) {
    int index = hashFunction(data); // Calcular la celda en la que se debe buscar el elemento
    Node* current = hashTable[index]; // Obtener el primer nodo de la celda
    while (current != NULL) { // Recorrer la lista enlazada de la celda
      if (current->getData() == data) { // Si se encuentra el elemento, devolver el puntero al nodo
        return current;
      }
      current = current->getNext(); // Avanzar al siguiente nodo en la lista
    }
    return NULL; // Si no se encuentra el elemento, devolver NULL
  }
  

  void List::hash_search(List* List_) {
  int data = 0;
  char ar_nums[5];
  OnlyNumbers_Validation obj_validate;
  cout << "\n\tIngrese el dato a buscar: ";
  obj_validate.natural_numbers(ar_nums);
  data = atoi(ar_nums);
  Node* result = List_->hashSearch(data); // Buscar el elemento en la tabla hash
  if (result != NULL) {
    cout << "\n\tEl dato se encuentra en la lista" << endl;
  } else {
    cout << "\n\tEl dato no se encuentra en la lista" << endl;
  }
}

