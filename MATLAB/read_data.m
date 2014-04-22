function [ E, nV, nE ] = read_data( nazwa_pliku )
E = {10000,4}; % we must succed!
nV = 0;
nE = 0;
metadata = {10,4};
if nazwa_pliku 
    fid = fopen(nazwa_pliku);
    tline = fgetl(fid);
    index = 1;
    while ischar(tline) 
        B =  regexp(tline,' ','split');
        bl = length(B);
        for i = 1:bl,
            if (i == 1 && B{i} == 'a')
               nE = nE + 1; 
            end
            if (index >= 6 && i > 1) 
                E{index-5,i-1}=str2double(B{i});
            elseif (index <= 5)
                metadata{index,i} = B{i};
            end
        end
        index = index + 1;
        tline = fgetl(fid);
    end
    fclose(fid);
    nV = str2double(metadata{5,2});
E = E();
end

end

