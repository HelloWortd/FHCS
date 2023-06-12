

function cplexbilpexl
% Use the function cplexbilp to solve a binary integer programming problem
%
% The bilp problem solved in this example is
%   Maximize  x1 + 2 x2 + 3 x3 + x4
%   Subject to
%      - x1 +   x2 + x3 + 10 x4 <= 20
%        x1 - 3 x2 + x3         <= 30
%               x2      - 3.5x4  = 0
%   Binary Integer
%       x1 x2 x3 x415% ---------------------------------------------------------------------------
% File: cplexbilpex.m
% Version 12.1.0
% ---------------------------------------------------------------------------
% Licensed Materials - Property of IBM
% 5724-Y48
% (c) Copyright IBM Corporation 2008, 2009. All Rights Reserved.
%
% disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
% ---------------------------------------------------------------------------

 try
    
   % Since cplexbilp solves minimization problems and the problem
   % is a maximization problem, negate the objective
 
  [a]=load('目标函数.txt');
   f     = a;
   [b]=load('不等式矩阵.txt');
   Aineq = b;
   [c]=load('不等式矩阵值.txt');
   bineq = c;
  % [d]=load('等式矩阵.txt');
  % Aeq   = d;
  % [e]=load('等式矩阵值.txt');
  % beq   =  e;
   %检验各个矩阵的行数和列数是否一致
   [m,n]=size(f);
   [a,b]=size(Aineq);
   [x,y]=size(bineq); 
   %[p,q]=size(Aeq);
   %[z,w]=size(beq);
    fprintf('ranks = %d\n',m,n,a,b,x,y);
    
   options = cplexoptimset;
   options.Diagnostics = 'on';   
   [x, fval, ~, output] = cplexbilp (f, Aineq, bineq, ...
      [ ], options);
  
   %当ln,i已知时，读取目标函数第二项常量
   fid = fopen('2.txt', 'r');
   ba = fscanf(fid, '%d');
   fclose(fid);
   
   %将目标函数的结果输出到文件中
   fid = fopen('backhaul_result.txt', 'a');
   fprintf(fid, '%d\t', fval-ba);
   fclose(fid);
    
   %将变量的结果输出到文件中
   fid = fopen('仿真结果.txt','w');
   fprintf(fid,'%f\t',x);
   fclose(fid);
   
   %显示目标函数的值和变量的值
   fprintf ('\nSolution status = %s\n', output.cplexstatusstring);   
   disp (x);
   disp ('Values = ');
   fprintf ('Solution value = %d\n', fval-ba);

   h=sum(x);
   disp('Sum = ');
   disp(h);
   

  
catch m
   disp(m.message);
end
end


