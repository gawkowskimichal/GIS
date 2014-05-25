function [ E, nV, nE ] = read_data( nazwa_pliku )
try
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
catch err
    display('Nast¹pi³ b³¹d przy odczytywaniu pliku wejœciowego.');
    display('Plik wejœciowy nie istnieje, lub ma z³¹ strukturê.');
    display('Plik wejœciowy powinien mieæ nastêpuj¹c¹ strukturê:');
    display('Linia 1: c Opis grafu');
    display('Linia 2: c Opis parametrów podanych w celu wytworzenia grafu');
    display('Linia 3: p kod_rodzaju liczba_wierzcho³ków liczba_krawêdzie');
    display('Linia 4: n numer_wierzcho³ka_pocz¹tkowego s');
    display('Linia 5: n numer_wierzcho³ka_koñcowego t');
    display('Linia 6 i kolejne: a numer_wierzcho³ka_pocz¹tkowego_krawêdzi numer_wierzcho³ka_koñcowego_krawêdzi przepustowoœæ_krawêdzi');
    return;
end
end

