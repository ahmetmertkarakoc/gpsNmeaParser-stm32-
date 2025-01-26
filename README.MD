# STM32 GPS Parser

## Genel Bakış
Bu proje, STM32 tabanlı bir GPS parser uygulamasıdır. DMA ve UART kullanarak NMEA-0183 formatındaki verileri verimli bir şekilde işler. Proje, GPS veri kaydı, navigasyon ve daha ileri işlem görevleri için tasarlanmıştır.

---

## Özellikler
- **DMA ve UART Entegrasyonu**: GPS veri akışlarını verimli bir şekilde yakalar ve işler.
- **NMEA Ayrıştırma**: GPS cümlelerini güçlü bir şekilde ayrıştırmak için `nmealib` kullanır.
- **Halka Tampon Uygulaması**: Kesintisiz ve kayıpsız veri işleme sağlar.
- **Konfigüre Edilebilir Tamponlar**: Farklı GPS veri yüklerini işlemek için ayarlanabilir tampon boyutları.
- **Gerçek Zamanlı Veri İşleme**: GPS akışlarını minimum gecikme ile gerçek zamanlı olarak işler.

---

## Gereksinimler
- **Donanım**: STM32 geliştirme kartı (STM32H750XBH6U üzerinde test edilmiştir)
- **Araç Takımı**: STM32CubeIDE
- **Kütüphaneler**: 
  - `nmealib`: NMEA ayrıştırma kütüphanesi ([GitHub Linki](https://github.com/Geontech/nmealib))

---

## Nasıl Çalışır?
1. **DMA Konfigürasyonu**: GPS verileri, verimli bir şekilde işlemek için UART üzerinden DMA ile alınır.
2. **Halka Tampon**: Veri kaybını önlemek için veriler halka tamponda saklanır.
3. **NMEA Ayrıştırma**: Veriler satır satır işlenir ve geçerli NMEA cümleleri ayrıştırılır.
4. **Çıktı**: Ayrıştırılmış GPS bilgileri (enlem, boylam, yükseklik vb.) daha fazla kullanım için işlenir.

---

## Kullanım
### 1. Depoyu Klonlayın
```bash
git clone <proje linki>
```

### 2. STM32CubeIDE'de Açın
Projeyi STM32CubeIDE'ye içe aktarın.

### 3. Donanımı Yapılandırın
GPS modülünü STM32 kartının uygun UART portuna bağlayın.

### 4. Derleyin ve Yükleyin
Kodu derleyin ve STM32 kartına yükleyin.

### 5. Çıktıyı İzleyin
Ayrıştırılmış GPS verilerini gözlemlemek için bir seri monitör kullanın.

---

## Konfigürasyon
- **Tampon Boyutları**: Farklı veri yüklerini işlemek için `main.c` içindeki `RX_BUFFER_SIZE` ve `PARSE_BUFFER_SIZE` değerlerini ayarlayın.
- **UART Ayarları**: UART konfigürasyonunun GPS modülünüzün baud hızı ve ayarlarıyla eşleştiğinden emin olun.

---

## Gelecekteki İyileştirmeler
- **Hata Yönetimi**: Geçersiz cümleler için geliştirilmiş hata tespiti ve düzeltme.
- **Kayıt**: GPS veri kaydı için SD kart desteği eklenmesi.
- **Gelişmiş İşleme**: Rota hesaplamaları ve harita entegrasyonu uygulanması.

---

## Lisans
Bu proje [MIT Lisansı](LICENSE) altında lisanslanmıştır.

---

## Teşekkürler
- NMEA ayrıştırma kütüphanesi için [nmealib](https://github.com/Geontech/nmealib).
