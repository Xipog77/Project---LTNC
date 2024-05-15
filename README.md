# Deffend the Kingdom

## Mô tả chung

Deffend the Kingdom là một trò chơi chiến thuật theo mô típ thủ thành. Lấy ý tưởng từ một trò chơi huyền thoại khác là Age of War, bạn sẽ phải điều hành và gọi ra những đơn vị quân của mình để chiến đấu chống lại kẻ thù bên kia chiến tuyến.

### Cách tải

Cài đặt toàn bộ file và chạy trên **Visual Studio**.

Bấm vào phần khởi động (được khoanh đỏ) để bắt đầu chạy trò chơi

    Current Document (main.cpp)

<img src="template_sdl\Image\README\Screenshot 2024-05-15 224015.png" width = "500">

Trong trường hợp lỗi không thể chạy được, hãy thử kiểm tra lại đường link của bạn với các thư viện SDL và hãy sửa lại ở phần
       
    Include Directories

    Library Directories

<img src="template_sdl\Image\README\Screenshot 2024-05-15 224341.png" width = "500">

### Cách chơi

Sau khi bắt đầu trò chơi, nhìn lên khung trên góc trái của màn hình, đây sẽ là nơi bạn gọi quân để phòng thủ.

  - **Warrior**: đây là những chiến binh dũng cảm sẽ trở thành tiền tuyến vững chắc cho bạn  
  - **Archer**: đây là những xạ thủ có tầm đánh xa, chắc chắn sẽ giúp ích cho những đơn vị quân ở phía trước.
  - **Knight**: họ là những kỵ sĩ dũng mãnh không chịu khuất phục trước bất cứ kẻ thù nào.
  - **Hero**: vị siêu hùng này chắc chắn sẽ đưa bạn đến chiến thắng, vì vậy hãy tiết kiệm đủ tiền để có thể triệu hồi họ nhé!

Ngoài ra, cũng có những phương thức hỗ trợ chiến đấu khác dành cho bạn:
  - **Balista** *chỉ có thể gọi một lần*: chiếc máy bắn đá này sẽ hỗ trợ bạn rất nhiều cho quá trình thủ thành. 
  - **Spell**: tia sét khổng lồ tấn công vào kẻ địch gần nhất.

  <img src="template_sdl\Image\README\Screenshot 2024-05-15 233639.png" width = "500">

Hãy nhớ rằng, bạn sẽ không thể tùy ý gọi quân. Vì mỗi lần gọi, bạn sẽ tiêu hao một lượng vàng nhất định. Để biết số lượng vàng bạn có, hãy nhìn lên góc phải của màn hình. 

Để có thêm vàng, bạn có thể thông qua những cách sau:
  - Vàng sẽ được tăng theo thời gian
  - Tiêu diệt một quân địch cũng sẽ cho thêm vàng
  - Tấn công nhà chính hoặc trùm cuối cũng sẽ cho thêm vàng

Bạn sẽ giành chiến thắng khi tiêu diệt được trùm cuối.
Hoặc bạn sẽ thua cuộc khi máu của nhà chính về 0.

## Phát triển

Trò chơi được phát triển với 3 phần lớn tượng trưng bằng 3 file .cpp là:
  - ***Function.cpp***: Đây là nơi diễn ra toàn bộ những hàm lớn nhất về cấu trúc của trò chơi.
  - ***Graphic.cpp***: Đây là nơi chứa các hàm về hình ảnh và âm thanh của SDL.
  - ***NPC.cpp***: Đây là nơi chứa các hàm và struct liên quan đến những npc và cơ chế của trò chơi. 

### Function.cpp

  Gồm các hàm:
  
  - **Play** Đây là hàm diễn ra toàn bộ trò chơi khi bắt đầu chơi, hàm trả về kết quả thắng/thua của phần chơi.
  - **Start_Exit** Đây là hàm diễn ra menu khi bắt đầu khởi động trò chơi. Hàm trả về kết quả chơi/kết thúc trò chơi,
  - **Win_Lose** Đây là hàm diễn ra menu sau khi kết thúc phần chơi. Hàm trả về kết quả chơi lại/kết thúc trò chơi. 

### Graphic.cpp

  Gồm các hàm:
  
  - **logSDLError**, **quitSDL**, **loadTexture**, **initWindow**, **initRenderer**: Các hàm khởi tạo mặc định liên quan đến SDL.
  - **Display_EnemyBase**, **Display_AllyBase**: Hàm hiển thị nhà chính của ta và địch.
  - **Display_SpawnButton**: Hàm hiển thị nút bấm gọi quân.
  - **ClickBox**: Hàm kiểm tra vị trí click chuột.
  - **Display_Gold**: Hàm hiển thị lượng vàng đang có.
  - **Display_Ally** **Display_Enemy** **Display_Background**: Hàm hiển thị quân ta, quân địch và màn hình nền.
  - **Display_Selection**: Hàm hiển thị nút lựa chọn ở phần menu.

### NPC.cpp

  Gồm các hàm:
    - **Ally** chứa các hàm về tấn công, di chuyển và lấy vị trí, hiển thị của quân ta.
    - **Enemy** chứa các hàm về tấn công, di chuyển và lấy vị trí, vàng trả về sau khi bị tiêu diệt , hiển thị của quân địch.

#### Clip.h

Ngoài ra, còn có file header Clip.h là nơi chứa các giá trị liên quan đến điểm ảnh để phục vụ cho animation.

## Tư liệu và tham khảo

Về chương trình: 
  - Chương trình được viết bằng ngôn ngữ lập trình **C++**
  - Sử dụng thêm thư viện đồ họa **SDL**
Về hình ảnh:

Những hình ảnh được mình tìm kiếm phần lớn trên Google hình ảnh và DevianArt. Sau đó sử dụng web [ezgif](https://ezgif.com) để chuyển những hình ảnh dạng gif về sprite chứa nhiều khung hình dạng .png

Những tác giả:

  - [Porforever](https://www.deviantart.com/porforever)
  - [Maxdemon6](https://www.deviantart.com/maxdemon6)
  - [Zedotagger](https://www.deviantart.com/zedotagger)

Về âm nhạc

  - [Âm Nhạc](https://www.youtube.com/watch?v=d2hRTLdvdnk&list=PLusYL_cFxfa4TNrRwNhoxBMMDgZOUMc8J&index=50): *Two Steps From Hell - To Glory*

Về Age of War

- [Age of War 1](https://ageofwargame.io)
- [Age of War 2](https://ageofwargame.io/age-of-war-2)

## Tác giả
**Đỗ Ngọc Khánh** - *23020615*    
[GitHub](https://github.com/Xipog77)
[Facebook](https://www.facebook.com/profile.php?id=100015122586295)

