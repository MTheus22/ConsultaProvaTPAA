void insertionSort(ListaAlunos* lista) {
    Aluno* atual = lista->inicio;
    while (atual != NULL) {
        Aluno* aux = atual->prox;
        while (aux != NULL && aux->matricula < atual->matricula) {
            // remove o nó atual da lista
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            } else {
                lista->inicio = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            }
            
            // insere o nó atual na posição correta
            Aluno* temp = aux->ant;
            aux->ant = atual;
            atual->prox = aux;
            atual->ant = temp;
            if (temp != NULL) {
                temp->prox = atual;
            } else {
                lista->inicio = atual;
            }
            
            // atualiza o ponteiro auxiliar
            aux = atual->prox;
        }
        atual = atual->prox;
    }
}
