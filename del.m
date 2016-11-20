s=size(output);
s=s(1);
for x=1:s
    for y=2:s
        if y<=x
            continue;
        end
        try if isempty(output(x,:))|isempty(output(y,:))
                continue;
            end
        catch ME
            continue;
        end
        if isempty(setdiff(output(x,:),output(y,:)))
            output(y,:)=[];
        end
    end
end
xlswrite('del.xls',output);
           
              