ya10ya25000 = 0
asgari = 2324.70
max_prim_alan_kisi = ""
max_prim_alan_maas = 0
max_prim_alan_prim = 0
max_prim_alan_tam_ucret = 0
min_prim_alan_kisi = ""
min_prim_alan_prim = 0
min_prim_alan_maas = 0
min_prim_alan_tam_ucret = 0
iyi_satici_sayi = 0
kota_dolduran_sayi = 0
en_iyi_adetci = ""
en_iyi_fiyatci = ""
toplam_kira = 0
toplam_satis = 0
satilan_en_yuksek_bedel_emlak_tip = ""
satilan_en_yuksek_bedel_emlakci = ""
satilan_en_yuksek_bedel = 0
satilan_emlak_adet = 0
kiralanan_Sayisi = 0
kiralanan_isyeri_sayisi = 0
kiralanan_konut_sayisi = 0
kiralanan_arsa_sayisi = 0
satilan_konut_sayisi = 0
satilan_isyeri_sayisi = 0
satilan_arsa_sayisi = 0
satilan_konut_topfiyat = 0
satilan_isyeri_topfiyat = 0
satilan_arsa_topfiyat = 0
kiralanan_konut_topfiyat = 0
kiralanan_isyeri_topfiyat = 0
kiralanan_arsa_topfiyat = 0
en_yuksek_kira = 0
asgariden_yuksek_kiralik_konut = 0
toplam_ucret = 0
primi_maasdan_yuksek = 0
toplam_komisyon=0
toplam_bedel=0
hic_Satamamislar=0
maxAdetSatisMiktari = 0
maxAdetSatanDanisman = ""
maxAdetSatisTutari = 0
maxBedelSatisMiktari = 0
maxBedelSatanDanisman = ""
maxBedelSatisTutari = 0
danismanlara_odenen_toplam_tutar = 0
while True:
    danisman_Sayisi = int(input("Kaç danışman çalışıyor"))

    if danisman_Sayisi > 0:
        break
for i in range(danisman_Sayisi):
    satisMiktari = 0
    danisman_toplam_komisyon = 0
    danisman_toplam_bedel=0
    ad_soyad = input("danışmanın adı soyadı nedir")
    while True:
        maas = float(input("maaş giriniz.Asgari ücrete eşit ya da fazla olmalıdır"))
        if maas >= asgari:
            break
        else:
            print("Asgari ücrete eşit ya da fazla olmalıdır")
    cevap = input("bu ay hiç satış yaptınız mı?(Ee,Hh):")
    while cevap not in "EeHh":
        print("wrong answer!")
        cevap = input("bu ay hiç satış yaptınız mı?(Ee,Hh):")
    if cevap in "hH":
        hic_Satamamislar += 1
    while cevap in "eE":
        satisMiktari += 1
        kota = maas * 10
        emlak_tipi = input("emlak tipini girin.Konut, İş yeri, Arsa (K/k/İ/i/A/a karakterleri)")
        while emlak_tipi not in "KkİiAa":
            print("hatalı giriş (K/k/İ/i/A/a karakterleri)")
            emlak_tipi = input("emlak tipini girin.Konut, İş yeri, Arsa (K/k/İ/i/A/a karakterleri)")
        if emlak_tipi in "kK":
            islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            while islem not in "SsKk":
                print("belirtilen harfleri giriniz.(S/s/K/k karakterleri)")
                islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            if islem in "Ss":
                bedel = float(input("Bedeli nedir"))
                satilan_konut_topfiyat += bedel
                satilan_konut_sayisi += 1

                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = float(input("Bedeli nedir"))
                    satilan_konut_topfiyat += bedel
                    satilan_konut_sayisi += 1
            elif islem in "Kk":
                bedel = float(input("Bedeli nedir"))
                kiralanan_konut_sayisi += 1
                kiralanan_konut_topfiyat += bedel
                if bedel > asgari:
                    asgariden_yuksek_kiralik_konut += 1
                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = float(input("Bedeli nedir"))
                    kiralanan_konut_sayisi += 1
                    kiralanan_konut_topfiyat += bedel
                    if bedel > asgari:
                        asgariden_yuksek_kiralik_konut += 1

        elif emlak_tipi in "İi":
            islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            while islem not in "SsKk":
                print("belirtilen harfleri giriniz.(S/s/K/k karakterleri)")
                islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            if islem in "Ss":
                satilan_isyeri_sayisi += 1
                bedel = float(input("Bedeli nedir"))
                satilan_isyeri_topfiyat += bedel
                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = float(input("Bedeli nedir"))
                    satilan_isyeri_topfiyat += bedel
            if islem in "Kk":
                kiralanan_isyeri_sayisi += 1
                bedel = float(input("Bedeli nedir"))
                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = input("Bedeli nedir")
                    kiralanan_isyeri_topfiyat += bedel

        elif emlak_tipi in "Aa":
            islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            while islem not in "SsKk":
                print("belirtilen harfleri giriniz.(S/s/K/k karakterleri)")
                islem = input("Satış mı yaptı kiralama mı (S/s/K/k karakterleri)")
            if islem in "Ss":
                satilan_arsa_sayisi += 1
                bedel = float(input("Bedeli nedir"))
                satilan_arsa_topfiyat += bedel

                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = float(input("Bedeli nedir"))
                    satilan_arsa_topfiyat += bedel
            elif islem in "Kk":
                kiralanan_arsa_sayisi += 1
                bedel = float(input("Bedeli nedir"))
                kiralanan_arsa_topfiyat += bedel

                while bedel < 0:
                    print("0dan büyük bir sayı giriniz")
                    bedel = float(input("Bedeli nedir"))
                    kiralanan_arsa_topfiyat += bedel
        kiralanan_Sayisi = kiralanan_arsa_sayisi + kiralanan_isyeri_sayisi + kiralanan_konut_sayisi
        if islem in "Ss":
            if bedel > satilan_en_yuksek_bedel:
                satilan_en_yuksek_bedel=bedel
                satilan_en_yuksek_bedel_emlak_tip = emlak_tipi
                satilan_en_yuksek_bedel_emlakci = ad_soyad
            komisyon = bedel * 0.04
        elif islem in "Kk":
            if bedel > en_yuksek_kira:
                en_yuksek_kira = bedel
                en_yuksek_kiraci = ad_soyad
            komisyon = bedel
        danisman_toplam_komisyon += komisyon
        if danisman_toplam_komisyon>kota:
            kota_durum="geçti"
        else:
            kota_durum="geçemedi"



        danisman_toplam_bedel += bedel
        if kiralanan_Sayisi > 10 or bedel > 25000:
            ya10ya25000 += 1

        cevap = input("başka satış var mı (e/h)")


    acente_toplam_komisyon = komisyon
    satilan_emlak_adet = satilan_arsa_sayisi + satilan_isyeri_sayisi + satilan_konut_sayisi
    toplam_satis = satilan_emlak_adet + kiralanan_Sayisi
    satilan_emlak_oran = (satilan_emlak_adet / toplam_satis) * 100
    satilan_toplam_fiyat = satilan_konut_topfiyat + satilan_arsa_topfiyat + satilan_isyeri_topfiyat
    kiralanan_oran = (kiralanan_Sayisi / toplam_satis) * 100
    kiralama_toplam_fiyat = kiralanan_konut_topfiyat + kiralanan_isyeri_topfiyat + kiralanan_arsa_topfiyat
    kira_ort = kiralama_toplam_fiyat / kiralanan_Sayisi

    toplam_komisyon+=danisman_toplam_komisyon
    toplam_bedel+=danisman_toplam_bedel
    prim = danisman_toplam_komisyon * 0.1
    if kota_durum=="geçti":
        ikramiye=asgari/2
    elif kota_durum=="geçemedi":
        ikramiye=0
    aylik_toplam_ucret = maas + prim + ikramiye
    if bedel > kota:
        kota_durum="geçti"
        kota_dolduran_sayi += 1
    elif bedel<kota:
        kota_durum="geçemedi"
    if satilan_toplam_fiyat > maxBedelSatisTutari:
        maxBedelSatisMiktari= satisMiktari
        maxBedelSatanDanisman= ad_soyad
        maxBedelSatisTutari= satilan_toplam_fiyat
    if satisMiktari > maxAdetSatisMiktari:
        maxAdetSatisMiktari = satisMiktari
        maxAdetSatanDanisman = ad_soyad
        maxAdetSatisTutari = satilan_toplam_fiyat
    if prim > maas:
        primi_maasdan_yuksek += 1
    if prim > max_prim_alan_prim:
        max_prim_alan_kisi = ad_soyad
        max_prim_alan_prim = prim
        max_prim_alan_maas =maas
        max_prim_alan_tam_ucret = aylik_toplam_ucret
    if prim < min_prim_alan_prim:
        min_prim_alan_kisi = ad_soyad
        min_prim_alan_prim = prim
        min_prim_alan_maas = maas
        min_prim_alan_tam_ucret = aylik_toplam_ucret
    danismanlara_odenen_toplam_tutar+=toplam_ucret


    print("adı soyadı", ad_soyad)
    print("Sattığı emlak adedi:{:.2f} kiraladığı emlak sayısı:{:.2f} ".format(satilan_emlak_adet,kiralanan_Sayisi))
    print("sattığı emlak oranı:{:.2f} kiraladığı emlak oranı: {:.2f}".format(satilan_emlak_oran,kiralanan_oran))
    print("toplam satılan bedelleri konut:{:.2f}(TL)/n iş yeri,arsa:{:.2f}(TL)/n iş yeri:{:.2f}(TL) ".format(satilan_konut_topfiyat,satilan_arsa_topfiyat,satilan_isyeri_topfiyat))
    print("kira ortalaması:{:.2f}(TL)".format(kira_ort))
    print("maaş(TL)",maas)
    print("prim(TL)",prim)
    print("kota(TL)",kota)
    print("o ay acenteye kazandırdığı toplam komisyon tutarı (TL)",danisman_toplam_komisyon)
    print("o ay kotasını doldurup dolduramadığı",kota_durum)
    print("o ay kotasını doldurduysa alacağı ikramiye (TL)",ikramiye)
    print("o ay toplam ücreti (TL){:.2f}".format(aylik_toplam_ucret))
print("satılan toplam konut:{:.2f}/n iş yeri:{:.2f}/n arsa:{:.2f}".format(satilan_konut_sayisi,satilan_isyeri_sayisi,satilan_arsa_sayisi))
toplam_emlak=satilan_emlak_adet+kiralanan_Sayisi
print("satılan emlak oranları: konut{:.2f}%/n işyeri {:.2f}%/n arsa {:.2f}%".format((satilan_konut_sayisi/toplam_emlak)*100,(satilan_isyeri_sayisi/toplam_emlak)*100,(satilan_arsa_sayisi/toplam_emlak)*100))
print("kiralanan toplam konut:{:.2f}/n iş yeri:{:.2f}/n arsa:{:.2f}".format(kiralanan_konut_sayisi,kiralanan_isyeri_sayisi,kiralanan_arsa_sayisi))
print("kiralanan emlak oranları: konut{:.2f}%/n işyeri {:.2f}%/n arsa {:.2f}%".format((kiralanan_konut_sayisi/toplam_emlak)*100,(kiralanan_isyeri_sayisi/toplam_emlak)*100,(kiralanan_arsa_sayisi/toplam_emlak)*100))
print("toplam satma bedeli konut:{:.2f}/n iş yeri:{:.2f}/n arsa:{:.2f}".format(satilan_konut_topfiyat,satilan_isyeri_topfiyat,satilan_arsa_topfiyat))
print("toplam kiralama bedeli konut:{:.2f}/n iş yeri:{:.2f}/n arsa:{:.2f}".format(kiralanan_konut_topfiyat,kiralanan_isyeri_topfiyat,kiralanan_arsa_topfiyat))
print("o ay en yüksek bedelle kiralanan konutun kira bedeli {:.2f}(TL), kiralayan danışmanın adısoyadı:{}".format(en_yuksek_kira,en_yuksek_kiraci))
print("o ay kiralanan konutlardan kira bedeli, aylık asgari net ücretten yüksek olan konutların sayısı:{:.2f}/n oranları:%{:.2f}".format(asgariden_yuksek_kiralik_konut,(asgariden_yuksek_kiralik_konut/kiralanan_Sayisi)*100))
print("o ay hiç satış yapamayan danışmanların sayısı {} ve tüm danışmanlar içindeki oranı:%{:.2f}".format(hic_Satamamislar,hic_Satamamislar/danisman_Sayisi*100))
print("en çok satış adedi yapan :{} sattığı emlak sayısı :{} toplam satış bedeli:{:.2f}".format(maxAdetSatanDanisman, maxAdetSatisMiktari, maxAdetSatisTutari))
print("en çok satış bedeli yapan:{} sattığı emlak sayısı :{} toplam satış bedeli:{:.2f}".format(maxBedelSatanDanisman, maxBedelSatisMiktari,maxBedelSatisTutari))
print("o ay kotasını dolduran danışmanların sayısı {:.2f}/n tüm danışmanlar içindeki oranı:%{:.2f}".format(kota_dolduran_sayi,(kota_dolduran_sayi/danisman_Sayisi)*100))
print("o ay primi maaşından yüksek olan danışmanların sayısı:{}/n  tüm danışmanlar içindeki oranı:%{:.2f}".format(primi_maasdan_yuksek,(primi_maasdan_yuksek/danisman_Sayisi)*100))
print("o ay en az 10 adet veya en az 25000 TL tutarında emlak kiralayan danışmanların sayısı",ya10ya25000)
print("o ay en yüksek prim alan danışmanın adı soyadı: {}, maaşı:{}, primi{} ve aylık toplam ücreti:{}".format(max_prim_alan_kisi, max_prim_alan_maas, max_prim_alan_prim, max_prim_alan_tam_ucret))
print("o ay en düşük prim alan danışmanın adı soyadı: {}, maaşı:{}, primi{} ve aylık toplam ücreti:{}".format(min_prim_alan_kisi, min_prim_alan_maas, min_prim_alan_prim, min_prim_alan_tam_ucret))
print("o ay tüm emlak danışmanlarına ödenecek toplam ücretlerin toplamı: {:.2f}(TL) ve ortalaması:%{:.2f}".format(danismanlara_odenen_toplam_tutar,(danismanlara_odenen_toplam_tutar/danisman_Sayisi)*100))
print("o ay acentenin kazandığı toplam komisyon {:.2f}(TL)".format(acente_toplam_komisyon))




#hiç satamayanlar(satır 188,en çok satış adedi(189) ve en yüksek gelir getiren(190),194,195
