#ifndef SCREEN_PICKER_H
#define SCREEN_PICKER_H

#include <Windows.h>

namespace QuickColorPicker {

	class ScreenPicker
	{

	public:

		ScreenPicker(COLORREF color = 0);
		~ScreenPicker();

		void Create(HINSTANCE inst, HWND parent);
		bool IsCreated() const {
			return (_mask_window != NULL);
		}

		void SetColor(COLORREF color);

		void Start();
		void End();

		bool IsShow() const {
			return _is_shown;
		}

	private:

		HINSTANCE _instance = NULL;
		HWND _parent_window = NULL;
		HWND _mask_window = NULL;
		HWND _info_window = NULL;

		bool _is_shown = false;

		HWND _zoom_area = NULL;

		HCURSOR _cursor = NULL;

		bool _slow_mouse = false;
		int _mouse_speed = 10;

		COLORREF _old_color = 0;
		COLORREF _new_color = 0;

		void CreateMaskWindow();
		static LRESULT CALLBACK MaskWindowWINPROC(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		BOOL CALLBACK MaskWindowMessageHandle(UINT message, WPARAM wparam, LPARAM lparam);

		void CreateInfoWindow();
		static BOOL CALLBACK InfoWindowWINPROC(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
		BOOL CALLBACK InfoWindowMessageHandle(UINT message, WPARAM wparam, LPARAM lparam);

		void PrepareInfoWindow() const;
		void PlaceInfoWindow(int x, int y) const;

		void SampleColor(int x, int y);

		void ReduceMouseSpeed();
		void RestoreMouseSpeed() const;
	};

}
#endif // SCREEN_PICKER_H