# 21020123_NguyenTienHoang
Amazing Mario Game !! CPP - LTNC - UET

I. Hướng dẫn cài đặt 
 1. Clone code từ branch "master" trong source https://github.com/hoangng-003/21020123_NguyenTienHoang.git
    - B1 : Tạo Folder MarioGame , open Git Bash tại folder này
    - B2 : git clone https://github.com/hoangng-003/21020123_NguyenTienHoang.git
    - B3 : Mở folder vừa tạo trong Visual Studio Code -> chuyển sang branch master
   
 2. Tải Mingw32 để run code C++ và thư viện đồ họa SFML
    - B1 : Tải và cài đặt theo hướng dẫn trong bài giảng
    - https://pie-cheque-188.notion.site/C-i-t-h-a-C-Windows-ef0a99a8dcae4dae86a39dc1cbc35980
    - B2 : Chạy lệnh mingw32-make để triển khai file run main.exe 
    - B3 : Chạy lệnh .\main.exe để bắt đầu Game
   
II. Mô tả dự án ( Project Description )
   1. Hình thức
      + Thuộc thể loại game phá đảo
      + Chinh phục các ải của trò chơi để giải cứu công chúa
      + Thay vì chạy nhẩy , dẫm nấm , ... như Mario thông thường , những map của Amazing Mario Game được set up vô cùng khó , làm cho người chơi khó chịu và ham muốn chinh phục được con game này hơn 
      + Tập trung chủ yếu vào Tối ưu hóa trải nghiệm người dùng & Đồ họa , làm con Game trở nên sinh động và cuốn hút , làm người chơi vẫn cảm thấy vui vẻ sau những lần thua lên thua xuống
      + Đầy đủ Menu , Map1,2,3 , Lose , Victory , ....
   
   2. Ví dụ sơ lược về các thức hoạt động của các ải
     - ải 1 : 
      + Tư duy cơ bản của người chơi sẽ là nhẩy lên phá gạch để ăn nấm , vì thế nên e đã cài đinh ẩn vào đó
      + Chạy thẳng qua cũng không được vì đã có tường ẩn chặn , quay ngược lại tìm đường sẽ bị đá rơi xuống .
      + Nhưng nếu người chơi để ý , khi bước vào vùng đá , gợi ý sẽ xuất hiện , làm theo để phá hủy bẫy và phá gạch ăn nấm
      + Nếu không chịu ăn , cây bên phải sẽ ăn và hóa to , đổ rầm xuống 
      + Nếu ăn sẽ hóa to , UFO đến bắt đi , bị thu nhỏ , đưa lên máy bay và qua ải sau .
     
     - Tương tự với ải 2 và 3 : 2 ải này sẽ dễ hiểu hơn một chút vì cũng tương đối quen thuộc       
     
III. Cấu trúc code ( Source Code )
  1. Phong cách code
 
  - Vì em dự định sẽ còn phát triển thêm con Game này trong tương lai khi có thời gian , nên em sẽ cố gắng viết code Hướng đối tượng nhất có thể
  - Về cơ bản , em sử dụng 1 Design Pattern là Singleton , có chức năng như 1 template dùng để quản lý nói chung
    + Em sử dụng để quản lý Resources ( Resources Manager ) và quản lý States ( GameStateManager )
    + Về cơ bản , quản lý Resources có thể hiểu như việc quản lý các đường dẫn Path , khi cần khởi tạo thực thể , chỉ cần gắn "name" cho đối tượng
              VD : Texture , Font , Music , Sound , .....
    + Với States , các States được kế thừa từ GameStateBase mang những tính năng cần có của 1 Game Page
    + Việc chuyển đổi giữa các States được xử lý bằng GameStateMachine , được thể hiện dưới dạng 1 danh sách List , cơ chế hoạt động như 1 ngăn xếp Stack , các States được Push chồng lên nhau và Pop để lấy ra .
  
  2. Kiến trúc phân tầng 
  
  - File main chỉ được dùng để Run , những triển khai đồ họa cơ bản ( Init , Update , Render ) được thể hiện trong file Application
  - Các chức năng được phân về từng trang ( Page / States )
  - Trong mỗi trang được khai báo các Thực thể , Triển khai các Thực thể bằng việc gắn cho chúng những thuộc tính cần có , Liên kết giữa các thực thể được thể hiện thông qua các hàm xử lý logic
  - Về cơ bản , em cố gắng triển khai các đối tượng theo mô hình Thực Thể - Liên Kết ( E-R ) tuy nhiên vì thời gian khá gấp nên chưa chỉnh chu được code trong từng trang

IV . Kết luận
  1. Ý nghĩa
    - Vì dự án lần này là sản phẩm cá nhân , nên e đã được phép show ra những kinh nghiệm e có trong việc build 1 Software Application , được làm những gì mình thích , triển khai những ý tưởng khá "ngốc nghếch" , học hỏi thêm được nhiều điều ý tưởng mới cũng như C++ Algorithms và SFML Graphic Library .
   
  2. Định hướng phát triển dự án
    - Nhờ việc viết Code hướng đối tượng nên việc Phát triển cũng như Debug rất dễ dàng .
      + Em dự định sẽ thêm những ải thú vị , trau truốt hơn về các hoạt động của từng ải , làm sao để chinh phục được 1 ải cần nhiều "não" nhất có thể , tạo được bất ngờ , khó chịu nhất định cho người chơi 
      + Trau truốt hơn về mặt hình ảnh và âm thanh , tối ưu hóa trải nghiệm người dùng sinh động nhất có thể
      + Hosting để mọi người cùng trải nghiệm và đánh giá 
    
