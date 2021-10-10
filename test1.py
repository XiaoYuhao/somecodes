

def remove_files(path):
    stack st, st2
    
    st.push(path)
    while is_not_empty(st):
        path = st.pop()
        for file in path:
            if is_empty(file) or is_subfile(file):
                delete(file)
            else:
                st.push(file)
        st2.push(path)
    while is_not_empty(st2):
        path = st2.pop()
        delete path