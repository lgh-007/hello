if(first_flag == 0){//判断第一个是否为（，如果不是直接返回错误
    first_flag = 1;
  if(*p!='('){
    printf("%d\n",-1);
    // printf("i am here");
    break;
  }
}
}else{//  (+ 9 18
  // printf("%d\n",s.top);
  //出栈   没有考虑到）这种先进栈的情况
  Pop(&s,&a);
  if((a<='0') || (a>='9'))
  {
    printf("%d\n",-1);
    break;
  }
ABC  DE G  F

A B C D E G F 



  printf("i am here");
  (* 2 3)
  (+ (* 2 3) (^ 4)
  ()
  (()
  (^ (^ (^ (* 1 1))))
  (+ (+ 9 18) (^ 1))()
  (* (+ 10 10) (^ 2))
  (+ 3 (* 10 1))
  (2)
  (2222)
  (+ 2 2 2)
  (/ 20 2)
  (* 2 (+ 1))
  (* -1 (+ (^ 5) (^ 5)))
  (+ +10 (* 1 2))
  (^ (+ 100 1) 5)
  ((^ 1))
  (+ 100 (^ (^ (^ (^ 10)))))
  (** 5 2)
  (+ 103 20)(* 12 7))
  (^ (+ (* 5 (^ 10)) 45) )
  (% 10 5)
  (++++++++++ 2 3)
  + 2 3
  // printf("i am a:%d\n",a);
  Pop(&s,&c);
  Pop(&s,&b);
  // printf("i am b:%d\n",b);
  // break;
  if(b == '^'){
    // printf("i am here");
    // printf("a:%d\n",a);
    tmp = ++a;
    // printf("fisrst：%d\n",tmp);
    if(s.top!=0){
      Pop(&s,&c);
      Push(&s,tmp);
    }else{
      printf("%d\n",tmp);
      break;
    }
  }else{
    //(+ (+ 9 18) (^ 1))()

  //  (+ (+ 9 18) 3) (^ 1))()
    // printf("i am here");
    Pop(&s,&d);
    // printf("%c\n",d);
    Pop(&s,&c);
    printf("%c\n",c);
    // printf("%d\n", s.top);
    switch(c){
      case '+':tmp = a+b;break;
      case '*':tmp = a*b;break;
    }
    if(s.top!=0){
      Pop(&s,&d);
      Push(&s,tmp);
      // printf("i am here");
    }else{
      printf("%d\n",tmp);
      break;
    }
  }
  p++;
}
