%number of steps
n = 5; 

%variables 
alpha = zeros(n,n); 
gamma = zeros(1,n);

%power matrix where ans will be stored
P = zeros(n,n); 

%getting the correct sign of each term
sign = [-1 -1 -1 -1 -1 ;
        1 -1 -1 -1 -1;
        1 1 -1 -1 -1;
        1 1 1 -1 -1;
        1 1 1 1 -1];  

for i = 1: n
    for j = 1: n
        alpha(i,j) = 0.33/4.2; 
    end
end 

for i = 1: n
    gamma (1,i) = 1;
    P(i,1) = 1; 
end 

disp(P)

p_tmp_arr = zeros(1,n); 

for step = 1: (n-1)
    %p_tmp; 
    for i = 1: n
        p_tmp = 0; 
        for j = 1: n
            if i == j
                p_tmp = p_tmp - gamma(1,i)*P(i,step); 
            elseif i ~= j
                    p_tmp = p_tmp + sign(i,j)*alpha(i,j)*P(i,step)*P(j,step); 
            end 
            
        end
        p_tmp = p_tmp*0.1 + P(i,step);
        P(i, step+1) = p_tmp; 
    end
end 
disp(P)

x = [1 2 3 4 5];

r1 = P(1,:); 
r2 = P(2,:); 
r3 = P(3,:); 
r4 = P(4,:); 
r5 = P(5,:); 

plot (x,r1); 

hold on; 

plot (x,r2);
plot (x,r3); 
plot (x,r4); 
plot (x,r5); 