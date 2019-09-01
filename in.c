














a#b#cdef#####
a##









cmp(temp,"..") != 0)
        {
            stack[k] = malloc(n + 1);
            strcpy(stack[k],temp);
            k++;
        }
    }
    if(k == 0)
        return "/";
    char* s = malloc(n+1);
    int m = 0;
    for(int i = 0;i < k;i++){
        s[m++] = '/';
        int j = 0;
        while(stack[i][j] != '\0')
            s[m++] = stack[i][j++];
    }
    s[m] = '\0';
    return s;
}

switch (*path) {
  case '/':

    if(GetTop(q)=='.'){
      Pop(q);
    }else{
      Push(q,*path);
    }
    break;
  case '.':
    if(GetTop(q) == '.'){
      while(flag == 0){
        if(Pop(q) == '/'){
          cnt++;
          if(StackEmpty(q)){
            Push(q,'/');
            cnt = 0;
            break;
          }
        }
        if(cnt >= 2){
          flag = 1;
          Push(q,'/');
          cnt = 0;
        }
      }
    }else{
      Push(q,*path);
    }
    break;
}





../a/.////./......./b/../c/asdd/.,.//
///oDPc///PnF/esaB/vPH/./qZl///./qC/../../////xFNu/cBh///qZ///XlmOR/SkC/./qKbXI/././P/dcFKB/n//
10
/../
/home/
"/..."
