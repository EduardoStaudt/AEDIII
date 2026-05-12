// PADROES LISTA

// VERIFICAR EXISTENCIA
//    if(li == NULL)
//         return 0;

// VERIFICAR SE ESTA VAZIA
//    if((*li) == NULL) 
//         return 0;




// ORDENAR UMA LISTA
int ordena_Lista(Lista* li){
    if(li == NULL) // verifica se a lista existe
        return 0;
    if((*li) == NULL) // verifica se a lista está vazia
        return 0;
    Elem* i; // ponteiro do primeiro laço
    Elem* j; // ponteiro do segundo laço
    struct aluno temp; // variável auxiliar para trocar os dados
    for(i = *li; i != NULL; i = i->prox){ // i percorre a lista do início ao fim
        for(j = i->prox; j != NULL; j = j->prox){ // j percorre os próximos nós depois de i
            if(i->dados.matricula > j->dados.matricula){ // se estiver fora de ordem
                temp = i->dados; // salva os dados de i
                i->dados = j->dados; // coloca os dados de j em i
                j->dados = temp; // coloca os dados antigos de i em j
            }
        }
    }
    return 1; // sucesso
}

// codigo da aula
/*int lista_remove_repetidos(Lista* li){
    if(lista_vazia(li))
        return 0;
    Elemento *atual = *li, *no = *li, *ant, *remov;
    while(atual != NULL){
        ant = atual;
        no = atual->prox;
        while(no != NULL){
            if(atual->dados.matricula == no->dados.matricula){
                remov = no;
                ant->prox = no->prox;
                no = no->prox;
                free(remov);
            }else{
                ant = no;
                no = no->prox;
            } 
        }
        atual = atual->prox;
    }
    return 1; 
}
*/