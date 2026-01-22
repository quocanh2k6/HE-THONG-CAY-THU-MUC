# 📂 HỆ THỐNG QUẢN LÝ CÂY THƯ MỤC (NHÓM 11)

Chào mừng bạn đến với dự án BTL Cấu trúc dữ liệu & Giải thuật. Dưới đây là hướng dẫn chi tiết cách cài đặt và sử dụng các chức năng.

---

## 🚀 1. Cách Biên Dịch & Chạy Chương Trình

Do code được tách thành 3 file (`main.cpp`, `Functions.cpp`, `DirectoryTree.h`), bạn **không thể** chỉ chạy file main đơn lẻ. Hãy làm theo cách sau:

### ✅ Cách dùng Terminal (Khuyên dùng)
Mở Terminal trong VSCode (`Ctrl + `) tại thư mục chứa code và gõ lệnh:

**Bước 1: Biên dịch**
```bash
g++ main.cpp Functions.cpp -o main
.\main
## 🎮 2. Hướng Dẫn Sử Dụng Menu Chi Tiết

Hệ thống hoạt động dựa trên các mã số (1, 2, 3...). Dưới đây là quy trình thao tác chuẩn:

---

### 1️⃣. Thêm thư mục con (Add Node) ➕
> **Mục đích:** Tạo nhánh mới cho cây thư mục.
* **Bước 1:** Nhập tên thư mục **Cha** (Nơi chứa).
* **Bước 2:** Nhập tên thư mục **Con** (Muốn tạo).
* 📝 *Ví dụ:* Cha: `root` ➜ Con: `TaiLieu`

---

### 2️⃣. Xóa thư mục (Delete Node) ❌
> **Mục đích:** Xóa một thư mục và toàn bộ nội dung bên trong nó.
* **Bước 1:** Nhập tên thư mục **Cha**.
* **Bước 2:** Nhập tên thư mục **Cần xóa**.
* ⚠️ *Cảnh báo:* Hành động này không thể hoàn tác!

---

### 3️⃣. Đổi tên (Rename) ✏️
> **Mục đích:** Chỉnh sửa tên thư mục bị sai hoặc cần cập nhật.
* **Bước 1:** Nhập tên thư mục **Hiện tại** (Cũ).
* **Bước 2:** Nhập tên thư mục **Mới**.
* ✅ *Kết quả:* Tên trên cây sẽ được cập nhật ngay lập tức.

---

### 4️⃣. Tìm kiếm & Đường dẫn (Find Path) 🔎
> **Mục đích:** Xác định vị trí chính xác của một file/thư mục.
* **Thao tác:** Nhập tên thư mục cần tìm.
* 📍 *Kết quả hiển thị:* `root / TaiLieu / BaiTap / C++`

---

### 5️⃣. Xem danh sách con (Print Children) 👁️
> **Mục đích:** Kiểm tra xem trong một thư mục có những gì.
* **Thao tác:** Nhập tên thư mục mẹ.
* 📋 *Kết quả:* Danh sách các thư mục con sẽ được liệt kê dọc.

---

### 6️⃣. Lưu file & Chỉnh sửa (Save & Edit) 💾
> **Mục đích:** Xuất cây thư mục ra file `.txt` và mở nhanh để sửa.
* **Bước 1:** Nhập **tên file** bạn muốn đặt (vd: `output.txt`).
* **Bước 2:** Chọn chế độ mở:
    * Nhập `1`: Mở ngay bằng **Notepad** (sửa xong nhớ Save lại).
    * Nhập `0`: Chỉ lưu và in nội dung ra màn hình console.

---

### 0️⃣. Thoat (Exit) 👋
* Thoát chương trình an toàn và giải phóng bộ nhớ.

---
> 💡 **Mẹo nhỏ:**
> * Luôn bắt đầu bằng việc thêm vào thư mục `root`.
> * Tên thư mục **không được chứa dấu cách** (VD: `Bai Tap` là sai ❌, `BaiTap` là đúng ✅).