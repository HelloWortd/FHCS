

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
 
  [a]=load('Ŀ�꺯��.txt');
   f     = a;
   [b]=load('����ʽ����.txt');
   Aineq = b;
   [c]=load('����ʽ����ֵ.txt');
   bineq = c;
  % [d]=load('��ʽ����.txt');
  % Aeq   = d;
  % [e]=load('��ʽ����ֵ.txt');
  % beq   =  e;
   %�����������������������Ƿ�һ��
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
  
   %��ln,i��֪ʱ����ȡĿ�꺯���ڶ����
   fid = fopen('2.txt', 'r');
   ba = fscanf(fid, '%d');
   fclose(fid);
   
   %��Ŀ�꺯���Ľ��������ļ���
   fid = fopen('backhaul_result.txt', 'a');
   fprintf(fid, '%d\t', fval-ba);
   fclose(fid);
    
   %�������Ľ��������ļ���
   fid = fopen('������.txt','w');
   fprintf(fid,'%f\t',x);
   fclose(fid);
   
   %��ʾĿ�꺯����ֵ�ͱ�����ֵ
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


