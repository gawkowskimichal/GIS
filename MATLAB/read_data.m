function [ E, nV, nE ] = read_data( nazwa_pliku )
%read_data - //funkcja odczytująca z pliku tekstowego dane opisujące
%sieć, w której wyznaczany będzie maksymalny przepływ
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
    display('Nast�pi� b��d przy odczytywaniu pliku wej�ciowego.');
    display('Plik wej�ciowy nie istnieje, lub ma z�� struktur�.');
    display('Plik wej�ciowy powinien mie� nast�puj�c� struktur�:');
    display('Linia 1: c Opis grafu');
    display('Linia 2: c Opis parametr�w podanych w celu wytworzenia grafu');
    display('Linia 3: p kod_rodzaju liczba_wierzcho�k�w liczba_kraw�dzie');
    display('Linia 4: n numer_wierzcho�ka_pocz�tkowego s');
    display('Linia 5: n numer_wierzcho�ka_ko�cowego t');
    display('Linia 6 i kolejne: a numer_wierzcho�ka_pocz�tkowego_kraw�dzi numer_wierzcho�ka_ko�cowego_kraw�dzi przepustowo��_kraw�dzi');
    return;
end
end

