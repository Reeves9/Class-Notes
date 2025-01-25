f = @(x) x^3 - x - 1; % the given function
a = 1; % initail guesses
b = 2;
err = 10^-4; % error toloerence
fa = f(a);
fb = f(b);
if fa*fb >= 0 % checking if bisection method is feseble
  disp('function must have opposite signs')
else
  while abs(b-a) > err  % main claculation
    mid = (a+b)/2;
    res = f(mid);
    if res > 0
      b = mid;
    elseif res < 0
      a = mid;
    else
      break
    endif
  endwhile
  fprintf("result is %f \n", mid) % output
end
