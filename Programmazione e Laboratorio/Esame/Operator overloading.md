### Copy assignment operator

Copy assignement operator deve eliminare gli elementi presenti nella lista da modificare e aggiungere gli elementi della lista da cui copiarli 

```c++
const ListDL& ListDL::operator=(const ListDL& l) {
    if( this != &l){ // protezione auto assegnamento
   
        pcella pc = head;
        while (pc != nullptr){
            pc = pc->next;
            delete head;
            head = pc;
        }
        head = nullptr;
        tail = nullptr;
        
        pc = l.head;
        while(pc != nullptr){
            append(pc->info);
            pc = pc->next;
        }
    }
    return *this;

}```

### move semantics

Ci permette di rubare degli spazi di memoria se questi sono rvalue temporanei ossia oggetti toranti dai una funzione


