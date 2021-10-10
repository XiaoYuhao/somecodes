


struct List{
    int val;
    struct List *next;
    List(){
        val = 0;
        next = nullptr;
    }
};

int main(){
    List *head = new List;
    head->val = 1;
    List *p, *q, *s;
    q = head;
    for(int i=1;i<10;i++){
        p = new List;
        p->val = i;
        q->next = p;
        q = p;
    }

    q = head;
    p = head->next;

    while(p){
        s = p->next;
        p->next = q;
        q = p;
        p = s;
    }
    head->next = nullptr;
    head = q;

}